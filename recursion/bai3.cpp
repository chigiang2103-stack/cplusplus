#include<iostream>
using namespace std;
int main () {
    int i = 10;
    while (i<=1000) {
        if (i%10==0) {
            cout << i<< " ";
            i=i+10;
        }
    }
    cout <<endl;
}