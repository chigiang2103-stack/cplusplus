#include<iostream>
using namespace std;
void daonguoc(int n ) {
    if(n==0) {
        return;
    }
        cout << n%10;
        daonguoc(n/10);
    
}

int main () {
    int n ; cout <<"input n : "; cin >>n;
    daonguoc(n);
}
