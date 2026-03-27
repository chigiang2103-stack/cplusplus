#include<iostream>
#include<stack>


using namespace std;

int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    stack<int>st;
    st.push(-1);
    string s;
    getline(cin,s);
    int len = 0;

    int count = 1;
    
    for (int i = 0 ; i < s.length(); i++) {
        if (s[i]=='(') {
            st.push(i);
        }
        else {
            st.pop();
            if (st.empty()) {
                st.push(i);
            }
            else {
                int cur_len = i - st.top();
                if (len < cur_len) {
                    len = cur_len;
                    count=1;
                }
                else if (cur_len == len && len > 0){
                    count++;
                }
            }
        }
    }
    if (len ==0 ) cout << "0 1" << endl;
    else cout << len << " "<< count << endl;



    return 0;


}