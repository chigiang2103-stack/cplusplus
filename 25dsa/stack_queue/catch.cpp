#include<iostream>
#include<stack>
using namespace std;

int main () {
    int l ; cin >> l;
    unsigned long long x = 0;
    const unsigned long long LIM  = (1Ull << 32)-1;
    stack<unsigned long long> st;
    st.push(1);
    
    while (l--) {
        string s;
        cin >> s;
        if (s == "for") {
            int n; cin >> n;
            unsigned long long temp = st.top();
            unsigned long long new_lim ;
            if (temp > LIM || temp*n > LIM) new_lim = LIM +1;
            else new_lim = temp*n;

            st.push(new_lim);

        }
        else if (s=="add") {
            x += st.top();
            if (x > LIM) {
                cout << "OVERFLOW!!!" << endl;
                return 0;
            }
        }else if (s=="end") {
            st.pop();
        }
    }
    cout << x<< endl;





    return 0;
}