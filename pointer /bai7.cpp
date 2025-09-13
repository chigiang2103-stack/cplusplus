#include<iostream>
using namespace std;
int main() {
    int n1,n2; 
    cout << "input n1 : "; cin >>n1;
    cout << "input n2 : ";cin>>n2;
    int *ptr1 = new int [n1];
    int *ptr2 = new int[n2];
    for (int i = 0 ; i < n1 ; i++) {
        printf("input value %d of n1 : ",i);
        cin >> *(ptr1 + i);
    }
     for (int i = 0 ; i < n2; i++) {
        printf("input value %d of n2 : ",i);
        cin >> *(ptr2 + i);
    }
    // list1 = 1 2 3  ; lis2 = 2 3 4 =>list= 1 2 2 3 3 4
    int *ptr = new int[n1+n2];
    int j =0,k=0;
    for (int i = 0 ; i<n1+n2;i++) {
        if (i<n1) {
            *(ptr+i) = *(ptr1+k);
            k++;
        }
        else {
            *(ptr+i) = *(ptr2+j);
            j++;
        }
    }
    // sort 
    int temp;
    for (int i = 0 ;i < n1 + n2-1 ; i++) {
        for (int j = i+1;j<n1+n2;j++) {
            if (*(ptr+i) > *(ptr+j)) {
                temp = *(ptr+i);
                *(ptr+i)= *(ptr+j);
                *(ptr+j) = temp;
            }
        }
    }
    for (int i =0 ; i < n1+n2 ;i++) {
    cout << *(ptr+i) <<" ";
    }
    cout << endl;


}
