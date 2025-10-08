#include<iostream> 
using namespace std;
int main () {
    string check_cot_hang (int n);
    string check_3x3 (int n);
    int t;
    cin >> t;
    char arr[9][9];
    string res="";
    for (int k = 1 ; k<=t;k++) {
        res = check_cot_hang(k);
        cout << res << endl;
    }
}
string check_cot_hang (int n) {
    char arr[9][9];
     for (int i = 0 ; i<9;i++) {
            for (int j = 0 ; j<9;j++) {
                cin >> arr[i][j];
            }
        }
    for (int k = 0;k<9;k++) {
        for (int i = 0;i<9;i++) {
            for (int j = i +1 ;j<9;j++) {
                if (arr[k][i] == arr[k][j] && arr[k][i]!='.' && arr[k][j]!='.') return "INVALID";
                if (arr[i][k] == arr[j][k] && arr[i][k]!='.' && arr[j][k]!='.') return "INVALID";
            }
        }
}
return "VALID";
}



