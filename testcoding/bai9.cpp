#include<iostream>
#include<vector>
using namespace std;
int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t , n ,k ;
    cout <<"";
    cin >> t;
    vector< vector <int> > arr(t,vector<int>(2));
    for (int i = 0 ; i<t;i++) {
        for (int j = 0 ; j < 2 ; j++) {
            cin >> arr[i][j];
        }
    }
    string fibonaci (int n );
    string tmp;
    for (int i = 0 ;i<t;i++) {
        n = arr[i][0];
        k = arr[i][1];
        tmp = fibonaci(n);
        cout << tmp[k-1] << endl;
    }
    return 0;
}
string fibonaci(int n) {
    if (n==0) {
        return "a";
    }
    if (n==1) {
        return "b";
    }
    if (n>1) {
        return fibonaci(n-2) + fibonaci(n-1);
    }
    return 0;
}