#include<iostream> 
using namespace std;
int main () {
    int a ,b , c;
    cout <<""; cin >>a>>b>>c;
    if(a<(b+c) && b<(a+c) && c < (a+b)) {
        cout<<"yes"<<endl;
    }
    else {
        cout <<"false"<<endl;
    }
}