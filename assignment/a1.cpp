#include<iostream>
using namespace std;
int main() {
    void bancuuchuong(int range,int nums);
    int range , nums ;
    cin >> range >> nums ;
    bancuuchuong(range,nums);
    return 0;
}
void bancuuchuong(int range , int nums ){
    for (int i = 1;i<=range ;i++) {
        cout << nums <<" * "<<i<<" = "<<nums*i<<endl;
    }
}
