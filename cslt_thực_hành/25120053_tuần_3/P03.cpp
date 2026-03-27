//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 
// 8.8
// 7.5
// 9.0
// 0
// Output : 8.5 PSSSED

// test Case 2 
// Input : 
// 4.9
// 8.9
// 6.0
// 0
// OutPut :6.5 PASSED

// Test Case 3 
// Input :
// 6.0
// 9.0
// 7.8
// 1
// Output : 0 FALLED


#include<iostream>
using namespace std;
int main () {
    float assignment , lab, final ;
    int cheating ;
    float total ;
    cin >> assignment;
    cin >> lab;
    cin >> final;
    cin >> cheating;
    total = assignment*0.3 + lab*0.3 + final*0.4 ;
    if (cheating == 0 ) {
        total = total ;
    }
    else {
        total = 0;
    }
    if (total >= 5) {
        printf("%.1f PASSED\n",total);
    }
    else {
        printf("%.1f FALLED\n",total);
        
    }
    return 0;
}
