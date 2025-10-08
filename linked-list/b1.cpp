#include<bits/stdc++.h>
using namespace std; 
class people {
    string name ;
    int age;
    string address;
    public :
    people() { // hàm khởi tạo
        name = address ="";
        age =0;
    }
    ~people() { // hàm huỷ
        name = address = "";
        age=0;
    }
    void set() { // hàm nhập
        cout << "nhập tên : " ;cin >> name;
        cout << "nhập tuổi : ";cin >> age;
        cout <<"nhập địa chỉ :"; cin >> address;

    }
    void get() { // hàm xuất
        cout << "tên : " << name << endl;
        cout <<"tuỏi : "<< age<<endl;
        cout <<"địa chỉ :" << address<<endl;
    }


};
class student : public people {
    int id , math , physical , chemistry ;
    public :
    student() {
        id = math = physical=chemistry = 0;
    }
    ~student(){
        id =math = physical =chemistry = 0;
    }
    void set(){
        people :: set(); // trỏ đến class people 
        cout <<"nhập id : "; cin >>id;
        cout <<"điểm toán :"; cin >> math;
        cout <<"điểm lý : ";cin >> physical;
        cout << "điểm hoá :"; cin>>chemistry;
    }
    void get(){
        people :: get(); // trỏ đến class people
        cout <<"id :"<<id<<endl;
        cout <<"GPA : "<<(math+physical+chemistry)/3 << endl;
    }

};
int main() {
    student a;
    a.set();
    a.get();
    return 0;
}