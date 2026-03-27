//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 7
// Output : 2.59

// test Case 2 
// Input : 20
// OutPut :3.60

// Test Case 3 
// Input : 100
// Output :5.19


#include<iostream>
using namespace std;
int main () {
    unsigned int n;
    cin >> n;
    double temp = 0;
    while (n>0) {
        temp+=1.0/n;
        n--;
    }
    printf("%.2f\n",temp);
    return 0;

}
