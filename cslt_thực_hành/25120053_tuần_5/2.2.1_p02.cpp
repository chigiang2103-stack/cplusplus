//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 
                    // input id :
                    // 25120053
                    // input fullname : 
                    // bùi chí giang
                    // input gpa : 
                    // 9.0
                    // input address : 
                    // hoà lễ
                    // input date of birth
                    // 21 03 2007
                    // input id : 
                    // 24120053
                    // input fullname : 
                    // đặng thế hoàng
                    // input gpa : 
                    // 9.3
                    // input address : 
                    // krong bong
                    // input date of birth
                    // 19 02 2007
// Output : 
                    // id : 25120053
                    // fullname : bùi chí giang
                    // gpa : 9.0
                    // address : hoà lễ
                    // date of birth : 21/3/2007
                    // id : 25120053
                    // first name : bùi
                    // last name :  chí giang
                    // gpa : 9.0
                    // address : hoà lễ
                    // date of birth : 21/3/2007
                    // age : 18 year 7 months 17 days 
                    // K25 class
                    // id : student 1 > student 2
                    // gpa : student 2 > student 1
                    // name : student 2 > student 1
                    // first name : student 2 > student 1
                    // last name : student 2 > student 1
                    // date_of_birth : student 2 > student 1

// test Case 2 
// Input : 
                    // input id : 
                    // 26092194
                    // input fullname : 
                    // nguyễn võ tuấn anh
                    // input gpa : 
                    // 8.9
                    // input address : 
                    // hcm 
                    // input date of birth
                    // 26 09 2007
                    // input id : 
                    // 26074924
                    // input fullname : 
                    // mai trường giang
                    // input gpa : 
                    // 6.8
                    // input address : 
                    // bình dương
                    // input date of birth
                    // 29 06 2007
// OutPut :
                    // id : 26092194
                    // fullname : nguyễn võ tuấn anh
                    // gpa : 8.9
                    // address : hcm 
                    // date of birth : 26/9/2007
                    // id : 26092194
                    // first name : nguyễn
                    // last name :  võ tuấn anh
                    // gpa : 8.9
                    // address : hcm 
                    // date of birth : 26/9/2007
                    // age : 18 year 1 months 12 days 
                    // K26 class
                    // id : student 1 > student 2
                    // gpa : student 1 > student 2
                    // name : student 2 > student 1
                    // first name : student 1 > student 2
                    // last name : student 1 > student 2
                    // date_of_birth : student 2 > student 1

// Test Case 3 
// Input : 
                    // input id : 
                    // 22030045
                    // input fullname : 
                    // phạm anh thư
                    // input gpa : 
                    // 8.0
                    // input address : 
                    // đà nẵng
                    // input date of birth
                    // 13 10 2007
                    // input id : 
                    // 24090049
                    // input fullname : 
                    // lê phương linh
                    // input gpa : 
                    // 8.0
                    // input address : 
                    // đắk lắk
                    // input date of birth
                    // 16 10 2007
// Output : 
                    // id : 22030045
                    // fullname : phạm anh thư
                    // gpa : 8.0
                    // address : đà nẵng
                    // date of birth : 13/10/2007
                    // id : 22030045
                    // first name : phạm
                    // last name :  anh thư
                    // gpa : 8.0
                    // address : đà nẵng
                    // date of birth : 13/10/2007
                    // age : 18 year 0 months 25 days 
                    // K22 class
                    // id : student 2 > student 1
                    // same gpa - id : student 2 > student 1
                    // name : student 1 > student 2
                    // first name : student 1 > student 2
                    // last name : student 2 > student 1
                    // date_of_birth : student 1 > student 2

#include<bits/stdc++.h>
using namespace std;

struct date_of_birth {
    int day;
    int month;
    int year;
    void inputdateofbirth();
};
void date_of_birth:: inputdateofbirth() {
    cout << "input date of birth" << endl;
    cin >> day >> month >> year;
}

struct student {
    date_of_birth dob;
    string id;
    string fullname;
    float gpa;
    string address;
    void input_infor();
    void output_infor_1(const student&stu1);
    void output_infor_2(const student&stu1);
    void find_class(const student&stu1);
    void compare_id(const student&stu1 , const student&stu2);
    void compare_gpa_id(const student&stu1 , const student&stu2);
    void compare_name_id(const student&stu1 , const student&stu2);
    void compare_firstname_id(const student&stu1 , const student&stu2);
    void compare_lastname_id(const student&stu1 , const student&stu2);
    void compare_dob_id(const student&stu1 , const student&stu2);

};
void find_first__last_name(string fullname) {
    int temp = fullname.find(" ");
    cout <<"first name : " << fullname.substr(0,temp) << endl;
    cout <<"last name : " << fullname.substr(temp,fullname.length())<<endl;
}
void find_age(int day , int month , int year) {
    year = 2025 - year;
    if (month > 11) {
        year = year -1;
        if (day>=7) {
            month=10;
            day = 31 - day + 7;
        }
        else {
            month=11;
            day = 7-day;
        }
    }
    else if (month == 11) {
        if (day>7) {
            month=11;
            day = 31-day+7;
        }
        else {
            month=0;
            day=7-day;
        }
    }
    else {
        if (day>7) {
            month = 11 - month -1;
            day = 31 - day + 7;
        }
        else {
            month = 11 - month;
            day = 7 - day;
        }
    }
    cout <<"age : " << year <<" year " << month <<" months " << day << " days " << endl;
  

}
void student::input_infor(){
    cout <<"input id : "<<endl;
    cin >> id;
    cout <<"input fullname : "<<endl;
    cin.ignore();
    getline(cin , fullname);
    cout <<"input gpa : "<<endl;
    cin >> gpa;
    cout <<"input address : "<<endl;
    cin.ignore();
    getline (cin, address);
    dob.inputdateofbirth();
}
void student::output_infor_1(const student&stu1){
    cout << "id : " << id << endl;
    cout <<"fullname : "<<fullname << endl;
    printf("gpa : %.1f\n",gpa);
    cout <<"address : "<< address << endl;
    cout <<"date of birth : "<< stu1.dob.day <<"/"<< stu1.dob.month <<"/"<< stu1.dob.year << endl;
}
void student::output_infor_2(const student&stu1) {
    cout << "id : " << id << endl;
    find_first__last_name(fullname);
    printf("gpa %.1f\n",gpa);
    cout <<"address : "<< address << endl;
    cout <<"date of birth : "<< stu1.dob.day <<"/"<< stu1.dob.month <<"/"<< stu1.dob.year << endl;
    find_age(stu1.dob.day , stu1.dob.month , stu1.dob.year);
}
void student::find_class(const student&stu1) {
    cout << "K"<<id.substr(0,2) <<" class"<< endl;
}
void student::compare_id(const student&stu1 , const student&stu2) {
    if (stu1.id > stu2.id) {
        cout << "id : student 1 > student 2" << endl;
    }
    else if (stu1.id == stu2.id) {
        cout << "id : student 1 = student 2" << endl;
    }
    else {
        cout << "id : student 2 > student 1" << endl;
    }
}
void student::compare_gpa_id(const student&stu1 , const student&stu2) {
    if (stu1.gpa > stu2.gpa) {
        cout << "gpa : student 1 > student 2" << endl;
    }
    else if (stu1.gpa == stu2.gpa) {
        cout <<"same gpa - ";
        compare_id(stu1,stu2);
    }
    else {
         cout << "gpa : student 2 > student 1" << endl;
    }
}
void student::compare_name_id(const student&stu1 , const student&stu2) {
    int index1 = stu1.fullname.rfind(" ");
    int index2 = stu2.fullname.rfind(" ");
    string name1 = stu1.fullname.substr(index1,stu1.fullname.length());
    string name2 = stu2.fullname.substr(index2,stu2.fullname.length());
    if (name1 > name2) {
        cout <<"name : student 1 > student 2"<<endl;
    }
    else if (name1==name2) {
        cout <<"same name - ";
        compare_id(stu1,stu2);
    }
    else {
        cout <<"name : student 2 > student 1"<<endl;
    }
}
void student::compare_firstname_id(const student&stu1 , const student&stu2) {
    int index1 = stu1.fullname.find(" ");
    int index2 = stu2.fullname.find(" ");
    string fname1 = stu1.fullname.substr(0,index1);
    string fname2 = stu2.fullname.substr(0,index2);
    if (fname1 > fname2) {
        cout <<"first name : student 1 > student 2"<<endl;
    }
    else if (fname1==fname2) {
        cout <<"same first name - ";
        compare_id(stu1,stu2);
    }
    else {
        cout <<"first name : student 2 > student 1"<<endl;
    }
}
void student::compare_lastname_id(const student&stu1 , const student&stu2) {
    int index1 = stu1.fullname.find(" ");
    int index2 = stu2.fullname.find(" ");
    string lname1 = stu1.fullname.substr(index1,stu1.fullname.length());
    string lname2 = stu2.fullname.substr(index2,stu2.fullname.length());
    if (lname1 > lname2) {
        cout <<"last name : student 1 > student 2"<<endl;
    }
    else if (lname1==lname2) {
        cout <<"same last name - ";
        compare_id(stu1,stu2);
    }
    else {
        cout <<"last name : student 2 > student 1"<<endl;
    }
}
void student::compare_dob_id(const student&stu1 , const student&stu2) {
    if (stu1.dob.year > stu2.dob.year) {
        cout <<"date_of_birth : student 2 > student 1" << endl;
    }
    else if (stu1.dob.year == stu2.dob.year ) {
        if (stu1.dob.month > stu2.dob.month) {
            cout <<"date_of_birth : student 2 > student 1" << endl;
        }
        else if (stu1.dob.month==stu2.dob.month) {
            if (stu1.dob.day > stu2.dob.day) {
                cout <<"date_of_birth : student 2 > student 1" << endl;
            }
            else if (stu1.dob.day == stu2.dob.day) {
                cout <<"same date_of_birth - ";
                compare_id(stu1,stu2);
            }
            else {
                cout << "date_of_birth : student 1 > student 2" << endl;
            }

        }
        else {
            cout << "date_of_birth : student 1 > student 2" << endl;
        }
    }
    else {
        cout << "date_of_birth : student 1 > student 2" << endl;
    }
}
int main () {
    student stu1;
    student stu2;
    stu1.input_infor();
    stu2.input_infor();
    stu1.output_infor_1(stu1);
    stu1.output_infor_2(stu1);
    stu1.find_class(stu1);
    stu1.compare_id(stu1,stu2);
    stu1.compare_gpa_id(stu1,stu2);
    stu1.compare_name_id(stu1,stu2);
    stu1.compare_firstname_id(stu1,stu2);
    stu1.compare_lastname_id(stu1,stu2);
    stu1.compare_dob_id(stu1,stu2);
    return 0;
}




