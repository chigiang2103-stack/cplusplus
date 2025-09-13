#include<iostream>
using namespace std;
int main () {
    int n ;
    cout << "input value of n: ";cin>>n;
    float sum(float n );
    float res=0.0;
    for (float i =0.0 ; i<=n;i++) {
        res += sum(i);
    }
    cout <<res <<endl;
}
    float sum (float n ) {
        return 1/(2*n+1);
    }



