#include<iostream> 
using namespace std;
int main () {
    int n ;
    cout <<""; cin >>n;
    int count,temp;
    // 18 = 3x6 = 5x3 +3x1 (dc chọn 3 or 5)
    // 21 = 3.7 = 5.3 + 3.2
    // n = 3.a + 5.b => a + b min 
    if (n%3!=0 && n%5 !=0 ) {
        cout <<-1;
    }
    else {
        for (int i = n/5 ; i>=0 ; i--) {
            temp = n - i*5;
            if (temp%3==0) {
                count = i + temp/3;
                break;
            }

        }
    }
    cout << count <<endl;

}