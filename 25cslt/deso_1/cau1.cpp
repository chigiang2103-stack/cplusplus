#include<iostream>
using namespace std;
void vecaythong(int h) {
    // số sao = 1 + (n-1)*2
    int t=h;
    for (int i=1;i<=h;i++) {
        for (int k = 1 ; k<= 1/2 +(t-1)&& t>=1;k++) {
            cout << " ";
        }
        t--;
        for (int j = 1 ; j<= 1 +(i-1)*2;j++) {
            cout << "*" ;
        }
        cout << endl;
    }
    int mid = 1/2 + (h-1) ;
    for (int i = 1;i<=4;i++){
        for (int k =1 ;k<=mid-1;k++) {
            cout <<" ";
        }
        for (int j = 1;j<=3;j++) {
            cout << "*";
        }
        cout << endl;

    }

}
int main () {
    int h;
    cin >> h;
    vecaythong(h);




    return 0;
}