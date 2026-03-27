#include<iostream>
#include<vector>
#include<algorithm>


using namespace std;
int bin_ser(vector<int>&a , int x, int left , int right ,int type){
    if (left>right) return -1;
    int mid = (left+right)/2;
    if (a[mid]==x) {
        if (type==1) {
            int temp =bin_ser(a,x,left,mid-1,type);
            if (temp==-1) return mid;
            return min(mid,temp);
        }
        if (type==2) return max(mid,bin_ser(a,x,mid+1,right,type));
    }
    if (a[mid] < x) {
        return bin_ser(a,x,mid+1,right,type);
    }
    if (a[mid] > x) return bin_ser(a,x,left,mid-1,type);
}
int main () {
    int n , q;
    cin >> n >> q;
    vector<int>a(n);
    for (int i=0;i<n;i++) cin >> a[i];
    vector<pair<int,int>>nums(q);
    for (int i = 0 ;i<q;i++) {
        cin >> nums[i].first >> nums[i].second;
    }

     for (int i = 0 ;i<q;i++) {
       cout << bin_ser(a,nums[i].second,0,n-1,nums[i].first) << endl;
    }




    return 0;
}