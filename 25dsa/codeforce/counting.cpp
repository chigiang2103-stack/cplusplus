#include <iostream>
#include <vector>
#include<map>

using namespace std;
vector<int>ans(500000);
long long cnt =0;
void mergeSort(vector<long long>& a, int left, int right) {
    if (left==right) return;
    int mid = (left + right)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid+1,right);

    int i = left;
    int j = mid + 1;
    int k = left;
    
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) ans[k]=a[i++];
        else {
            ans[k]=a[j++];
            cnt += (mid -1) ;
        }
        k++;
    }
    while (i <= mid) ans[k++]=a[i++];
    while (j<=right) ans[k++]=a[j++];
    for (int i =left  ; i <=  right;i++) a[i] = ans[i];

}
int main () {
    int n ; cin >> n;
    vector<long long> a(n);
    for (int i = 0 ; i < n;i++) cin >> a[i];
    mergeSort(a,0,n-1);
 
    cout << cnt;





    return 0;
}