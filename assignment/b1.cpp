#include<iostream>
using namespace std;
#include<vector>
int main() {
    // 10 = 1 + 2 +3 +4
    // 24 = 7 + 8 + 9 
    // 1 2 3 4 5 6 7 8 9 10 11 12 13
    vector<int>arr;
    int n;
    cin >>n;
    for (int i = 1 ;i<=n/2;i++) {
        arr.push_back(i);
    }
    int left = 0,right =1;
    int sum=0;
    int indexL , indexR;
    bool flag = true;
    sum = arr[left]+ arr[right];
    for (int i =0 ;i<sizeof(arr);i++){
        left = i;
        while (sum < n) {
            right++;
            sum+=arr[right];
        }
        if (sum==n) {
            flag = false;
            indexL = left;
            indexR = right;
        }
        sum = sum - arr[left];
    }
    if (flag) {
        cout << "IMPOSSIBLE" << endl;
    }
    else {
        cout << n <<"="<<arr[indexL];
         for (int i = indexL+1; i<= indexR;i++) {
                cout << "+" << arr[i] ;
            }
         cout << endl;
    }
    return 0;

}
