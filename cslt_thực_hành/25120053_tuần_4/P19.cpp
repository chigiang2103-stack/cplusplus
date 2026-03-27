//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 20 20
// Output : 242580783.27

// test Case 2 
// Input : 11 11
// OutPut :29929.68

// Test Case 3 
// Input :50 50
// Output :2592352764164799201280.00

#include<iostream>
using namespace std;
int main () {

    long double n; 
    cin >> n; 

    unsigned int m; 
    cin >> m; 
    long double res = 1+n;
    long double temp=n;

    for (int i=1;i<=m;i++) {
        temp=temp*n*n/((2.0*i)*(2.0*i+1.0));
        res += temp;
    }
    printf("%.2Lf\n",res);

}


