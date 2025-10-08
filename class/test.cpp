#include<bits/stdc++.h>
using namespace std;
int main () {
    ifstream fileinput("/Users/buichihau/Documents/cplusplus/class/testcase.txt");
    ofstream fileoutput("/Users/buichihau/Documents/cplusplus/class/output.txt");
    if (fileinput.fail() || fileoutput.fail()) {
        cout << "failed " << endl;
    }
    int n , arr[20];
    fileinput >>n;
    int i=0;
    while (!fileinput.eof()) {
        fileinput>>arr[i];
        i++;
    }
    cout << arr[4]<<endl;
    fileinput.close();
    fileoutput.close();







    return 0;
}