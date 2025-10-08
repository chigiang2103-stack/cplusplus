#include<bits/stdc++.h>
using namespace std;
int main () {
    int x , n;
    cin >> x >> n;
    int s = 0;
    for (int i =1 ;i <= n ; i++ ) {
        s+= pow(-1,i+1)*pow(x,i);
    }
    cout << s << endl;
    return 0;
}