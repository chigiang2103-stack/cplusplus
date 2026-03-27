#include<iostream>
using namespace std;
int main () {
    bool check (int &n);
    int n ; cin >> n;
   bool flag ;
   flag = check(n);
   cout << flag << endl;
    return 0;
}
bool check (int &n) {
    int temp=0;
    int k = n;
    while (n!=0) {
        temp= temp*10 + n%10;
        n=n/10;
    }
    if (k==temp) {
        return true;
    }
    else {
        return false;
    }
}