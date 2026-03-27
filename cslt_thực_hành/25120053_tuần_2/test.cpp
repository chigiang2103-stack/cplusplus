#include<iostream>
using namespace std;
int main () {
    int n; cin >> n;
    for (int i = 1; i<n;i++){
        for (int  j = 0; j<i;j++) {
            if (i==n-1) {
                cout << "*";
            }
            else {
                if (j==0 || j==i-1 ) {
                cout <<"*";
            }
            else {
                cout <<" ";
            }
            }
        }
        cout << endl;
    }



    return 0;

}