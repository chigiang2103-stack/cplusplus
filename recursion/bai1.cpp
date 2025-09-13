#include<iostream>
using namespace std;
int main () {
    int n; 
    do {
        cout <<"input n :";
        cin>>n;
    }
    while (n>100); 
    for (int i = n ; i<=100;i=i+2) {
        cout <<i<<" ";
    }
    
    cout <<endl;


}
