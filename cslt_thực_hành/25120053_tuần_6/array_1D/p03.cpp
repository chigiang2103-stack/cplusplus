//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 
            // course id : CSC10001
            // course name : Programing edu
            // max students : 100
            // min students : 1
            // current student : 3
            // student thứ 1
            // input id : 25120053
            // input fullname : Bùi Chí Giang
            // input gpa : 9.0
            // input address : đắk lắk
            // input date of birth : 21 03 2007

            // student thứ 2
            // input id : 24120019
            // input fullname : Lê Văn Chánh
            // input gpa : 8.7
            // input address : hồ chí minh
            // input date of birth : 19 9 2007

            // student thứ 3
            // input id : 19112034
            // input fullname : Đặng Hoàng Long
            // input gpa : 9.3
            // input address : hà nội
            // input date of birth : 20 11 2007
// Output : 
            // course id : CSC10001
            // course name : Programing edu
            // status : open
            // id : 25120053
            // fullname : Bùi Chí Giang
            // gpa : 9.0
            // address : đắk lắk
            // date of birth : 21/3/2007
            // id : 24120019
            // fullname : Lê Văn Chánh
            // gpa : 8.7
            // address : hồ chí minh
            // date of birth : 19/9/2007
            // id : 19112034
            // fullname : Đặng Hoàng Long
            // gpa : 9.3
            // address : hà nội
            // date of birth : 20/11/2007

            // add new student : 
            // input id : 19112049
            // input fullname : Nguyễn Đình Dương
            // input gpa : 6.7
            // input address : bình thuận
            // input date of birth : 29 9 2007
            // add valid 

            // remove student thứ : 2
            // romved student id : 24120019 total students : 3
            // status course : open

            // students born in month 11 : 
            // student thứ 2 : Đặng Hoàng Long
            // student id :19112034
            // date of birth : 20/11/2007

            // students born in date 9 : 
            // No students borin in date 9

            // students have driving licences : 
            // student thứ 1 : Bùi Chí Giang
            // student id :25120053
            // date of birth : 21/3/2007
            // student thứ 3 : Nguyễn Đình Dương
            // student id :19112049
            // date of birth : 29/9/2007

            // students are in K19 class : 
            // student thứ 3 : Nguyễn Đình Dương
            // student id :19112049
            // date of birth : 29/9/2007

            // input id want to search : 25120053
            // id : 25120053
            // fullname : Bùi Chí Giang
            // gpa 9.0
            // address : đắk lắk
            // date of birth : 21/3/2007

            // input name want to search : dương
            // id : 19112049
            // fullname : Nguyễn Đình Dương
            // gpa : 6.7
            // address : bình thuận
            // date of birth : 29/9/2007

            // list students sorted by id : 
            // 19112034 - Đặng Hoàng Long
            // 19112049 - Nguyễn Đình Dương
            // 25120053 - Bùi Chí Giang

            // list students sorted by first name : 
            // Nguyễn Đình Dương - 19112049
            // Bùi Chí Giang - 25120053
            // Đặng Hoàng Long - 19112034

            // list students sorted by gpa : 
            // 6.7 - Nguyễn Đình Dương - 19112049
            // 9.0 - Bùi Chí Giang - 25120053
            // 9.3 - Đặng Hoàng Long - 19112034

            // list students sorted by dob : 
            // 20/11/2007 - Đặng Hoàng Long - 19112034
            // 29/9/2007 - Nguyễn Đình Dương - 19112049
            // 21/3/2007 - Bùi Chí Giang - 25120053
// test Case 2 
// Input : 
            // course id : COC19119911
            // course name : physical edu
            // max students : 100
            // min students : 1
            // current student : 4
            // student thứ 1
            // input id : 22002004
            // input fullname : Hồ Văn Dũng
            // input gpa : 9.3
            // input address : đà lạt
            // input date of birth : 9 9 2008

            // student thứ 2
            // input id : 19192003
            // input fullname : 
            // input gpa : 9.1
            // input address : đắk nông
            // input date of birth : 22 10 2007

            // student thứ 3
            // input id : 23110044  
            // input fullname : Đặng Duy
            // input gpa : 7.5
            // input address : thanh hoá
            // input date of birth : 30 12 2007

            // student thứ 4
            // input id : 22113366
            // input fullname : Đỗ Phủ
            // input gpa : 9.9
            // input address : Hà giang
            // input date of birth : 10 10 2007
// OutPut :
            // course id : COC19119911
            // course name : physical edu
            // status : open
            // id : 22002004
            // fullname : Hồ Văn Dũng
            // gpa : 9.3
            // address : đà lạt
            // date of birth : 9/9/2008
            // id : 19192003
            // fullname : 
            // gpa : 9.1
            // address : đắk nông
            // date of birth : 22/10/2007
            // id : 23110044
            // fullname : Đặng Duy
            // gpa : 7.5
            // address : thanh hoá
            // date of birth : 30/12/2007
            // id : 22113366
            // fullname : Đỗ Phủ
            // gpa : 9.9
            // address : Hà giang
            // date of birth : 10/10/2007

            // add new student : 
            // input id : 19192222
            // input fullname : Lê Hoài An
            // input gpa : 7.6
            // input address : đắk Mil
            // input date of birth : 22 11 2009
            // add valid 

            // remove student thứ : 2
            // romved student id : 19192003 total students : 4
            // status course : open

            // students born in month 11 : 
            // student thứ 4 : Lê Hoài An
            // student id :19192222
            // date of birth : 22/11/2009

            // students born in date 9 : 
            // student thứ 1 : Hồ Văn Dũng
            // student id :22002004
            // date of birth : 9/9/2008

            // students have driving licences : 
            // student thứ 3 : Đỗ Phủ
            // student id :22113366
            // date of birth : 10/10/2007

            // students are in K19 class : 
            // student thứ 4 : Lê Hoài An
            // student id :19192222
            // date of birth : 22/11/2009

            // input id want to search : 19192222
            // id : 19192222
            // fullname : Lê Hoài An
            // gpa : 7.6
            // address : đắk Mil
            // date of birth : 22/11/2009

            // input name want to search : phủ
            // id : 22113366
            // fullname : Đỗ Phủ
            // gpa : 9.9
            // address : Hà giang
            // date of birth : 10/10/2007

            // list students sorted by id : 
            // 19192222 - Lê Hoài An
            // 22002004 - Hồ Văn Dũng
            // 22113366 - Đỗ Phủ
            // 23110044 - Đặng Duy

            // list students sorted by first name : 
            // Lê Hoài An - 19192222
            // Đặng Duy - 23110044
            // Hồ Văn Dũng - 22002004
            // Đỗ Phủ - 22113366

            // list students sorted by gpa : 
            // 7.5 - Đặng Duy - 23110044
            // 7.6 - Lê Hoài An - 19192222
            // 9.3 - Hồ Văn Dũng - 22002004
            // 9.9 - Đỗ Phủ - 22113366

            // list students sorted by dob : 
            // 22/11/2009 - Lê Hoài An - 19192222
            // 9/9/2008 - Hồ Văn Dũng - 22002004
            // 30/12/2007 - Đặng Duy - 23110044
            // 10/10/2007 - Đỗ Phủ - 22113366

// Test Case 3 
// Input : 
            // course id : CHC192001
            // course name : Chemistry edu
            // max students : 100
            // min students : 1
            // current student : 3 
            // student thứ 1
            // input id : 19112200
            // input fullname : Hồ Hoàng Duy
            // input gpa : 8.7
            // input address : Quảng nam
            // input date of birth : 23 8 2007

            // student thứ 2
            // input id : 20222025
            // input fullname : Đặng Toàn 
            // input gpa : 9.4
            // input address : Nghệ an
            // input date of birth : 31 10 2007

            // student thứ 3
            // input id : 19200342
            // input fullname : Kiều An Hoài
            // input gpa : 8.7
            // input address : lắk
            // input date of birth : 31 12 2007
// Output : 
            // course id : CHC192001
            // course name : Chemistry edu
            // status : open
            // id : 19112200
            // fullname : Hồ Hoàng Duy
            // gpa : 8.7
            // address : Quảng nam
            // date of birth : 23/8/2007
            // id : 20222025
            // fullname : Đặng Toàn
            // gpa : 9.4
            // address : Nghệ an
            // date of birth : 31/10/2007
            // id : 19200342
            // fullname : Kiều An Hoài
            // gpa : 8.7
            // address : lắk
            // date of birth : 31/12/2007

            // add new student : 
            // input id : 25120042
            // input fullname : Hoàng Quốc Khang
            // input gpa : 6.7
            // input address : Tân phú
            // input date of birth : 10 12 2007
            // add valid 

            // remove student thứ : 3
            // romved student id : 19200342 total students : 3
            // status course : open

            // students born in month 11 : 
            // No students borin in motnh 11

            // students born in date 9 : 
            // No students borin in date 9

            // students have driving licences : 
            // student thứ 1 : Hồ Hoàng Duy
            // student id :19112200
            // date of birth : 23/8/2007
            // student thứ 2 : Đặng Toàn
            // student id :20222025
            // date of birth : 31/10/2007

            // students are in K19 class : 
            // student thứ 1 : Hồ Hoàng Duy
            // student id :19112200
            // date of birth : 23/8/2007

            // input id want to search : 25120042
            // id : 25120042
            // fullname : Hoàng Quốc Khang
            // gpa : 6.7
            // address : Tân phú
            // date of birth : 10/12/2007

            // input name want to search : hoàng
            // id : 19112200
            // fullname : Hồ Hoàng Duy
            // gpa : 8.7
            // address : Quảng nam
            // date of birth : 23/8/2007
            // id : 25120042
            // fullname : Hoàng Quốc Khang
            // gpa : 6.7
            // address : Tân phú
            // date of birth : 10/12/2007

            // list students sorted by id : 
            // 19112200 - Hồ Hoàng Duy
            // 20222025 - Đặng Toàn
            // 25120042 - Hoàng Quốc Khang

            // list students sorted by first name : 
            // Hồ Hoàng Duy - 19112200
            // Hoàng Quốc Khang - 25120042
            // Đặng Toàn - 20222025

            // list students sorted by gpa : 
            // 6.7 - Hoàng Quốc Khang - 25120042
            // 8.7 - Hồ Hoàng Duy - 19112200
            // 9.4 - Đặng Toàn - 20222025

            // list students sorted by dob : 
            // 10/12/2007 - Hoàng Quốc Khang - 25120042
            // 31/10/2007 - Đặng Toàn - 20222025
            // 23/8/2007 - Hồ Hoàng Duy - 19112200
#include<iostream>
using namespace std; 

struct date_of_birth {
    int day;
    int month;
    int year;
    void inputdateofbirth();
};
void date_of_birth:: inputdateofbirth() {
    cout << "input date of birth : ";
    cin >> day >> month >> year;
}

struct student {
    date_of_birth dob;
    string id;
    float gpa;
    string fullname;
    string address;
    void input_infor();
    void output_infor_1(const student&stu1);
    string find_class(const student&stu1);
    bool check_age(const student&stu1);
    string to_tolower(const student&stu1);
    string find_first_name(const student&stu1);
    bool compare_dob(const student&stu1 , const student&stu2);
};

void student::input_infor(){
    cout <<"input id : ";
    cin >> id;
    cout <<"input fullname : ";
    cin.ignore();
    getline(cin , fullname);
    cout <<"input gpa : ";
    cin >> gpa;
    cout <<"input address : ";
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
string student::find_class(const student&stu1) {
    return "K" + id.substr(0,2);
}
string student::to_tolower(const student&stu1) {
    string name1 = stu1.fullname;
    for (int i = 0;i<name1.length();i++) {
        name1[i]=tolower(name1[i]);
    }
    return name1;
}
bool student::check_age(const student&stu1){
    if (2025-stu1.dob.year>18) {
        return true;
    }
    else if (2025-stu1.dob.year<18) {
        return false;
    }
    else {
        if (stu1.dob.month<11) {
            return true;
        }
        else if (stu1.dob.month>11) {
            return false;
        }
        else {
            if (stu1.dob.day<=9) {
                return true;
            }
            else {
                return false;
            }
        }
    }
    return true;
}
string student::find_first_name(const student&stu1) {
    int index1 = stu1.fullname.rfind(" ");
    string fname1 = stu1.fullname.substr(index1+1,stu1.fullname.length());
    return fname1;
}
bool student::compare_dob(const student&stu1 , const student&stu2) {
    if (stu1.dob.year > stu2.dob.year) {
        return false;
    }
    else if (stu1.dob.year == stu2.dob.year ) {
        if (stu1.dob.month > stu2.dob.month) {
            return false;
        }
        else if (stu1.dob.month==stu2.dob.month) {
            if (stu1.dob.day > stu2.dob.day) {
                return false;
            }
            else {
                return true;
            }

        }
        else {
            return true;
        }
    }
    else {
        return true;
    }
    return true;
}
struct course {
    string course_id;
    string course_name;
    string status;
    int max_sts;
    int min_sts;
    int numstudent;
    student arr[100];
    void input_course();
    void output_course(const course&course1);
    void add_student(const course&course1);
    void remove_student(const course&course1);
    void find_sts_same_month(const course&course1);
    void find_sts_same_date(const course&course1);
    void find_sts_legal(const course&course1);
    void find_sts_k19_class(const course&course1);
    void find_sts_id(const course&course1);
    void find_sts_name(const course&course1);
    void sort_id(const course&course1);
    void sort_first_name(const course&course1);
    void sort_gpa(const course&course1);
    void sort_dob(const course&course1);

};

void course::input_course() {
    cout << "course id : " ;
    cin >> course_id;
    cout <<"course name : ";
    cin.ignore();
    getline(cin,course_name);
    cout <<"max students : ";
    cin >> max_sts;
    cout <<"min students : ";
    cin >> min_sts;
    do {
        cout << "current student : ";
        cin >> numstudent;
    }
    while (numstudent < min_sts ||  numstudent > max_sts);
    for (int i = 0 ;i<numstudent;i++) {
        cout <<"student thứ " << i+1<<endl;
        arr[i].input_infor();
        cout << endl;
    }
}
void course::output_course(const course&course1) {
    cout << "course id : " << course_id << endl;
    cout <<"course name : "<<course_name << endl;
    if (numstudent >= min_sts && numstudent <= max_sts) {
        cout <<"status : " <<"open"<<endl;
    }
    else {
        cout <<"status : "<<"close"<<endl;
    }
    for (int i = 0 ;i<numstudent;i++) {
        arr[i].output_infor_1(arr[i]);
    }

}
void course::add_student(const course&course1) {
    cout << endl;
    cout <<"add new student : " << endl;
    arr[numstudent].input_infor();
    numstudent++;
    if (numstudent<=max_sts) {
        status = "open";
        cout <<"add valid "<<endl;
    }
    else {
        status = "close";
        cout <<"add invalid"<<endl;
    }
}
void course::remove_student(const course&course1) {
    int index;
    cout << endl;
    cout <<"remove student thứ : ";
    cin >> index;
    cout << "romved student id : " << arr[index-1].id <<" total students : "<< numstudent-1 << endl;
    for (int i = index-1 ;i<numstudent;i++) {
        arr[i]=arr[i+1];
    }
    numstudent--;
    if (numstudent < min_sts) {
        status = "close";
        cout <<"status course : " << status << endl;
    }
    else {
        status="open";
        cout <<"status course : "<<status<<endl;
    }
}
void course::find_sts_same_month(const course&course1) {
    bool flag = true;
    cout << endl;
    cout <<"students born in month 11 : "<<endl;
    for (int i = 0 ;i<numstudent ;i++) {
        if (arr[i].dob.month==11) {
            cout <<"student thứ "<<i+1<<" : " << arr[i].fullname<<endl;
            cout <<"student id :"<<arr[i].id<<endl;
            cout <<"date of birth : "<< arr[i].dob.day <<"/"<< arr[i].dob.month <<"/"<< arr[i].dob.year << endl;
            flag = false;
        }
    }
    if (flag) cout <<"No students borin in motnh 11" << endl;
}
void course::find_sts_same_date(const course&course1){
    bool flag = true;
    cout << endl;
    cout <<"students born in date 9 : "<<endl;
    for (int i = 0 ;i<numstudent ;i++) {
        if (arr[i].dob.day==9) {
            cout <<"student thứ "<<i+1<<" : " << arr[i].fullname<<endl;
            cout <<"student id :"<<arr[i].id<<endl;
            cout <<"date of birth : "<< arr[i].dob.day <<"/"<< arr[i].dob.month <<"/"<< arr[i].dob.year << endl;
            flag = false;
        }
    }
    if (flag) cout <<"No students borin in date 9" << endl;
}
void course::find_sts_legal(const course&course1){
    cout << endl;
    cout <<"students have driving licences : "<<endl;
    bool flag=true;
    for (int i = 0 ;i<numstudent;i++){
        if(arr[i].check_age(arr[i])) {
            cout <<"student thứ "<<i+1<<" : " << arr[i].fullname<<endl;
            cout <<"student id :"<<arr[i].id<<endl;
            cout <<"date of birth : "<< arr[i].dob.day <<"/"<< arr[i].dob.month <<"/"<< arr[i].dob.year << endl;
            flag = false;
        }
    }
    if (flag) cout <<"no students legal "<<endl;
}
void course::find_sts_k19_class(const course&course1) {
    bool flag=true;
    cout << endl;
    cout <<"students are in K19 class : " << endl;
    for (int i = 0 ;i<numstudent ;i++) {
        if (arr[i].find_class(arr[i])=="K19") {
            cout <<"student thứ "<<i+1<<" : " << arr[i].fullname<<endl;
            cout <<"student id :"<<arr[i].id<<endl;
            cout <<"date of birth : "<< arr[i].dob.day <<"/"<< arr[i].dob.month <<"/"<< arr[i].dob.year << endl;
            flag = false;
        }
    }
    if (flag) cout <<"No students are in K19 class" << endl;

}
void course::find_sts_id(const course&course1) {
    cout << endl;
    cout <<"input id want to search : ";
    string id_search;
    cin.ignore();
    getline(cin,id_search);
    bool flag=true;
    for (int i = 0 ; i < numstudent ;i++) {
        if(id_search==arr[i].id) {
            arr[i].output_infor_1(arr[i]);
            flag=false;
        }
    }
    if (flag) cout <<"Not found " << endl;

}
void course::find_sts_name(const course&course1)  {
    cout << endl;
    cout <<"input name want to search : ";
    string name_search;
    cin.ignore();
    getline(cin,name_search);
    bool flag = true;
    for (int i = 0 ;i<numstudent ;i++){
        if(arr[i].to_tolower(arr[i]).find(name_search) != string::npos){
            arr[i].output_infor_1(arr[i]);
            flag=false;
        }
    }
    if (flag) cout <<"not found"<<endl;
}
void course::sort_id(const course&course1){
    student temp;
    for (int i = 0 ; i<numstudent-1 ;i++) {
        for (int j = i+1;j<numstudent;j++) {
            if (arr[i].id > arr[j].id) {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout << endl;
    cout << "list students sorted by id : " << endl;
    for (int i = 0 ;i<numstudent ;i++){
        cout <<arr[i].id<<" - " << arr[i].fullname<<endl;
    }

}
void course::sort_first_name(const course&course1){
    student temp;
    for (int i = 0 ; i<numstudent-1 ;i++) {
        for (int j = i+1;j<numstudent;j++) {
            if (arr[i].find_first_name(arr[i]) > arr[j].find_first_name(arr[j])) {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout << endl;
    cout << "list students sorted by first name : " << endl;
    for (int i = 0 ;i<numstudent ;i++){
        cout << arr[i].fullname <<" - "<<arr[i].id<<endl;
    }
}
void course::sort_gpa(const course&course1){   
    student temp;
    for (int i = 0 ; i<numstudent-1 ;i++) {
        for (int j = i+1;j<numstudent;j++) {
            if (arr[i].gpa > arr[j].gpa) {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout << endl;
    cout << "list students sorted by gpa : " << endl;
    for (int i = 0 ;i<numstudent ;i++){
        printf("%.1f",arr[i].gpa);
        cout <<" - " << arr[i].fullname <<" - " <<arr[i].id<<endl;
    }
}
void course::sort_dob(const course&course1){
    student temp;
    for (int i = 0 ; i<numstudent-1 ;i++) {
        for (int j = i+1;j<numstudent;j++) {
            if (arr[i].compare_dob(arr[i],arr[j])) {
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    cout << endl;
    cout << "list students sorted by dob : " << endl;
    for (int i = 0 ;i<numstudent ;i++){
        cout <<arr[i].dob.day <<"/"<< arr[i].dob.month <<"/"<< arr[i].dob.year<<" - " << arr[i].fullname <<" - " <<arr[i].id<<endl;
    }

}

int main() {
    course course1;
    course1.input_course();
    course1.output_course(course1);
    course1.add_student(course1);
    course1.remove_student(course1);
    course1.find_sts_same_month(course1);
    course1.find_sts_same_date(course1);
    course1.find_sts_legal(course1);
    course1.find_sts_k19_class(course1);
    course1.find_sts_id(course1);
    course1.find_sts_name(course1);
    course1.sort_id(course1);
    course1.sort_first_name(course1);
    course1.sort_gpa(course1);
    course1.sort_dob(course1);
}









