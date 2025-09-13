#include<iostream> 
using namespace std;
int main () {
    int n ;
    cout <<""; cin >>n;
    int find(int n );
    int res=n;
    bool flag = true ;
    for (int i = n/2 +1 ; i <n ; i++) {
        if (find(i)==n) {
            res = i;
            flag = true ;
            break;
        }
        else {
            flag = false;
        }
    } 
    if (flag) {
        cout << res <<endl;
    }
    else {
        cout <<"false" <<endl;
    }
    

}
int find(int n ) {
     int temp = n , res =temp;
    while (temp > 0) {
        res +=temp%10;
        temp = temp/10;
    }
    return res;
}

