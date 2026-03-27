//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 14
// Output : 1 2 7 14

// test Case 2 
// Input : 1000
// OutPut : 1 2 4 5 8 10 20 25 40 50 100 125 200 250 500 1000

// Test Case 3 
// Input :293
// Output : 1 293


#include<iostream>
using namespace std;
int main () {
    void list_divisors(unsigned int n);
    unsigned int n;
    cin >> n;
    list_divisors(n);
    return 0;
}
void list_divisors(unsigned int n){
    for (int i=1;i<=n/2;i++) {
        if(n%i==0) {
            cout << i <<" ";
        }
    }
    cout << n;
    cout << endl;
}