#include<bits/stdc++.h>
using namespace std;
class student {
    public:
    string name ;
    int age;
    void display() {
        cout<<"ten" << this -> name << endl;
        cout<<"tuổi" << age <<endl;
    }
    void getintfo() {
        cout << "nhập tên : ";
        cin>>name;
        cout <<"nhập tuổi : ";
        cin >> age;


    }

};
int main() {
    student a;
    a.getintfo();
    a.display();


    return 0;
}

