#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0 ;i<n;i++) {
        cin >> arr[i];
    }
    int sum=0 , count=0;
    for (int i = 0 ;i<n;i++) {
       if (arr[i]%2==0) {
            sum+=arr[i];
            count++;
       }
    }
    double avg = sum*1.0/count;
    printf("%.2f\n",avg);
    

    return 0;

}