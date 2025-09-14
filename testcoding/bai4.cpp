#include<iostream> 
using namespace std;
int main () {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n ;
    cout <<""; cin >>n;
    int count=0;
    bool flag = true; 
    for (int i = n/5 ; i>=0 ; i--) {
        int temp = n - i*5;
        if (temp%3==0) {
            count = i + temp/3;
            flag = true;
            break;
            }
        else {
            flag = false;
        }
    }
    if (flag) cout << count << endl;
    else cout <<-1<<endl;
    return 0;
}