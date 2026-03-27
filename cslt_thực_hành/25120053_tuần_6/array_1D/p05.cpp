#include<iostream>
using namespace std;
#define MAX 100
int main() {
    int n;
    cin >> n;
    int arr[MAX];
    for (int i = 0 ;i<n;i++) {
        cin >> arr[i];
    }
    int temp;
    cout << n << endl;
    for (int i = 0 ;i<n-1;i++) {
        for (int j=i+1;j<n;j++) {
            if (arr[i] > arr[j] && arr[i]%2==0 && arr[j]%2==0) {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    for(int i=0;i<n;i++) {
        cout << arr[i]<<" ";
    }
    cout << endl;









    return 0;

}

