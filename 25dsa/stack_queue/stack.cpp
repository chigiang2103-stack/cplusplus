#include<iostream>
#include<vector>
#include<algorithm>
#include<stack>


using namespace std;
bool check_valid(string s,stack<char>st) {
     for ( char c : s) {
        if (c==')') {
            if ( st.size() && st.top() == '(' ) {
                st.pop();
            }else {
                return false;
            }
        }
        else if (c==']') {
            if (st.size()&&st.top() == '[') {
                st.pop();
            }else {
                return false;
            }
        }
        else if (st.size()&&c=='}') {
            if (st.top() == '{') {
                st.pop();
            }else {
                return false;
            }
        } else {
            st.push(c);
        }
    }
    return st.empty();
}

int main () {
    stack<char>st;
    string s;
    getline(cin,s);

   
    if (check_valid(s,st)) cout << "YES" ;
    else cout << "NO";



    return 0;


}