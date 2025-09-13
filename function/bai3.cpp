#include<iostream>
using namespace std;
int main () {
    int n ;
    cout << "input n : "; cin >>n;
    string arr[20];
    for (int i = 0 ; i< n; i++) {
        printf("input string %d : ",i) ;
        cin >> arr[i];
    }
    string res=arr[0],result;
    string hauto(string a, string b) ;
    for (int i = 1 ; i<n; i++) {
        res = hauto(res,arr[i]);
    }
        for (int i = res.length()-1;i>=0 ; i--) {
        result += res[i];
    }
    cout << result << endl;
}
string hauto(string a,string b) {
    string res="";
    int la=a.length() ;
    int lb = b.length();
    int j =lb;
        for (int i = lb-1;i>=0;i--) {
            if (a[i]==b[j]) {
                res +=a[i];
                j--;
            }
        }
    return res;
}