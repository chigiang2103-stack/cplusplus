// #include <iostream>
// #include <stack>
// using namespace std;
// int main () {
//     string s;
//     cout <<""; cin >>s;
//     stack<char>st; 
//     int i = 0;
//     int k;
//     for (char x : s) {
//         if (x == '(') {
//             st.push(x);
//             k=i;
//             i++;
//         }
//         else {
//             if (st.top() == '(') {
//                 cout << k <<" ";
//                 st.pop();
//                 k--;
//                 i=i+1;
//             }  
//         }
//     }
// }
#include <iostream>
using namespace std;
#include <stack>
#include <vector>
int main() {
    string S;
    cin >> S;
    stack<int> st;
    vector<int> result;
    
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(') {
            st.push(i); 
        } else {
            int pos = st.top(); st.pop();
            result.push_back(pos);
        }
    }
    for (int x : result) {
        cout << x <<" ";
    }
    cout << endl;
    return 0;

}
