//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 9 1 3 8
// Output : 9 1 

// test Case 2 
// Input : 1 6 3 2
// OutPut :6 1

// Test Case 3 
// Input : 19 18 3 7
// Output : 19 3


#include<iostream>
using namespace std;
int main () {
    int a , b, c, d ;
    cin>> a >> b>>c >>d;
    int max=a , min=b ;
    if (b>max) {
        max = b ;
        min = a; 
    }
        if (c>max) { 
            max = c;
        }
        else { 
            if (min>c) { 
                min = c; 
                }
            }
         if (d>max) {
                max = d;
            }
            else {
                if (min >d) {
                    min =d;
                    }
        }
        
    
    cout << max << " " << min << endl;
    return 0;
}
