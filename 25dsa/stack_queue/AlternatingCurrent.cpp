#include<iostream>
#include<stack>


using namespace std;
bool check_valid(string s,stack<char>&st) {
     for ( char c : s) {
        if (!st.empty() && st.top() ==c) {
            st.pop();
        }
        else {
            st.push(c);
        }
    }
    return st.empty();
}

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<char>st;
    string s;
    getline(cin,s);
    if (check_valid(s,st)) cout << "YES" ;
    else cout << "NO";



    return 0;


}