#include<bits/stdc++.h>
#include<iostream>
using namespace std;
#include<vector>
int main () {
    string chuoichungdainhat(string a);
    string s;
    cin >> s;
    cout << chuoichungdainhat(s) << endl;

    // abbda abccba
    return 0;
}
string chuoichungdainhat(string a) {
    int n=a.length();
    int start=0;
    int maxlen=1;
    auto expand = [&] (int l , int r) {
        while (0<=l && r < n && a[l]==a[r]){
            if (r - l + 1 > maxlen) {
                maxlen = r - l + 1;
                start = l;
            }
            l--;
            r++;
        }
    };
    for (int i = 0 ;i<n;i++) {
        expand(i,i);
        expand(i,i+1);
    }
    return a.substr(start,maxlen);
}