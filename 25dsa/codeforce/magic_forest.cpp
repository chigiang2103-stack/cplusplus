#include<iostream>
using namespace std;
int main () {
    int n ; 
    cin >> n;
    int cnt = 0;
    for (int a = 1 ; a <= n;a++) {
        for (int b = a; b <= n;b++) {
            int c = a xor b ;
            if ( b <= c && c <= n && a + b>c) {
                    cnt++;
                }
        }
    }
    cout << cnt << "\n";




    return 0;
}