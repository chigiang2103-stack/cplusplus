#include<bits/stdc++.h>
using namespace std;
class student {
    string name ;
    int age;
    string gender;
    double math;
    double english;
    double physical;
    public :
    void getinfor() {
        cout <<"nhập tên : "; cin >>name;
        cout <<"Nhập tuổi : "; cin >> age;
        cout <<"Giới tính : "; cin >> gender;
        cout <<"điểm toán : "; cin >> math;
        cout <<"điển anh : "; cin>>english;
        cout <<"điểm lý : " ; cin >> physical;
    }
    void getgpa() {
        cout << "gpa : "<<(math+english + physical)/3 << endl;
    }
    void display() {
        cout <<"tên : "<<name << endl;
        cout <<"tuổi : "<<age<<endl;
        cout <<"giới tính : "<<gender<<endl;
    }
    
};
int main () {
    student a;
    a.getinfor();
    a.display();
    a.getgpa();
    return 0;
}