// #include<iostream>
// using namespace std;
// int main () {
//     int n; cout <<"nhập n : "; cin >>n;
//     int binary(int n );
//     cout << binary(n) <<endl;
// }
// // 10 => 5 dư 0 => 2 dư 1=> 1 dư 0 => 0 dư 1 => 1010
// int binary(int n ) {
//     if (n==1) return 1;
//     return n%2 + 10*binary(n/2) ;
// }
#include <iostream>
using namespace std;

void nhiphan(int n){
    if (n!=0){
        nhiphan(n/2);
        cout << n%2;
    };
}

int main() {
    int n = 10;

    nhiphan(n);
    
    return 0;
}