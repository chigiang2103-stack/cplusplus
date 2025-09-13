#include<iostream>
using namespace std;
int main () {
    int n ;
    cout << "input value of n : "; cin >>n;
    // 100 = 1*2^2 + 0*2^1 + 0*2^0 = 4
    int convert(int n );
    cout << convert(n)<<endl;
}
int convert(int n) {
    int sum=0,temp=n,i=0;
    while (temp >0) {
        sum += temp%10*(pow(2,i));
        temp= temp/10;
        i++;
    }
    return sum;
}