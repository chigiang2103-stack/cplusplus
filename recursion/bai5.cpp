#include<iostream>
using namespace std;
int main () {
    int n; cout <<"nhập n : "; cin >>n;
    int sumle(int n ) ;
    cout << sumle(n) <<endl;
}
int sumle(int n ) {
    if (n==0 || n==1) {
        return 1;
    }
    else {
        if (n%2==0) return (n-1) +sumle(n-3) ;
        return n +sumle(n-2);
    }
}