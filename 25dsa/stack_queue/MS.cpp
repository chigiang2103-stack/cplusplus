#include<iostream>
#include<stack>
#include<vector>

using namespace std;

// s : cdb
// t : 
// u : 



int main () {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s ; cin >> s;
    vector<int>cnt(26,0);
    // a = 0 -> z = 25
    for (char c : s) {
        cnt[c-'a']++;
    }
    stack<char>t;
    string u="";
    int min_char =0;
    for (char c : s) {
        t.push(c);
        cnt[c-'a']--;
        while (min_char < 26 && cnt[min_char]==0) min_char++;
        while (!t.empty() && (t.top()-'a') <= min_char) {
            u+=t.top();
            t.pop();
        }
        
        
    }
    while (!t.empty()) {
        u+=t.top();
        t.pop();
    }
    

    cout << u << endl;




  


    return 0;


}