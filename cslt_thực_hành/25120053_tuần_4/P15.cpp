//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 20
// Output : 1.90

// test Case 2 
// Input : 9999
// OutPut :2.00

// Test Case 3 
// Input :11
// Output :1.83

#include<iostream>
using namespace std;
int main () {
    unsigned long long tong(int n);
    unsigned int n;
    cin >> n;
    double temp =0;
    while (n>0) {
        temp += 1.0/tong(n);
        n--;
    }
    printf("%.2f\n",temp);
    
    return 0;
}
unsigned long long tong(int n) {
    long long temp=0;
    while (n>0) {
        temp+=n;
        n--;
    }
    return temp;
}

