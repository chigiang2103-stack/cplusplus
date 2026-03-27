//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 14
// Output : 4

// test Case 2 
// Input : 10000
// OutPut : 25

// Test Case 3 
// Input :293
// Output : 2


#include<iostream>
using namespace std;
int main () {
    int the_number_of_divisors(unsigned int n);
    unsigned int n;
    cin >> n;
    cout << the_number_of_divisors(n)<<endl;
    return 0;
}
int the_number_of_divisors(unsigned int n){
    int count =1;
    for (int i=1;i<=n/2;i++) {
        if(n%i==0) {
            count++;
        }
    }
    return count ;
}