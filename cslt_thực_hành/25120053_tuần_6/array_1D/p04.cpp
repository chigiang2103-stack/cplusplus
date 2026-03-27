
#include<iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int m=1;
    long long arr[10000];
    long long a[10000];
    for (int i = 0 ;i<n;i++) {
        cin >> arr[i];
    }
    int count=1;
    bool flag=true;
    a[0]=arr[0];
    for (int i =1;i<n;i++) {
        int temp=arr[0];
        if (temp != arr[i]) {
            for (int j=0;j<i;j++) {
                int k=arr[i];
                if (k==arr[j]) {
                    flag=false;
                }
            }
            if (flag) {
                count++;
                a[m++]=arr[i];
            }
        }
    }
    cout << count << endl;
    for (int i = 0 ;i<m;i++) {
        cout << a[i] <<" ";
    }
    cout << endl;


    return 0;
    
    }






