//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 999
// Output : 992.51

// test Case 2 
// Input : 20
// OutPut :17.35

// Test Case 3 
// Input :1000000000
// Output :999999983.49


#include<iostream>
using namespace std;
int main () {
    unsigned int n;
    cin >> n;
    double temp = 0;
    while (n>0) {
        temp+=(double)n/(n+1);
        n--;
    }
    printf("%.2f\n",temp);
    return 0;

}
