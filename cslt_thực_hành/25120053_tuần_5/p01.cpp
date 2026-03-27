//25120053
//Bùi Chí Giang
//25CTT1

// Test Case 1 
// input : 1999 1 1
// Output : 1999 - 01 - 01
//          Jan - 01 - 19
//          1999 - 01 - 02
//          1998 - 12 - 31

// test Case 2 
// Input : 2025 4 11
// OutPut :2025 - 04 - 11
//         Apr - 11 - 20
//         2025 - 04 - 12
//         2025 - 04 - 10


// Test Case 3 
// Input : 2020 12 1
// Output : 2020 - 12 - 01
//          Dec - 01 - 20
//          2020 - 12 - 02
//          2020 - 11 - 30


#include<bits/stdc++.h>
using namespace std;
struct date {
    int day;
    int month;
    int year;
    void inputdate();
    void outputdate(const date&date1);
    void outputdate2(const date&date1);
    void tomorow(const date&date1);
    void yesterday(const date&date1);
    void increase(const date&date1);
    void decrease(const date&date1);
    void compare(const date&date1 ,const date&date2);
    void compute_v_1(const date&date1);
    void compute_v_2(const date&date1);
    void compute_v_3(const date&date1,const date&date2);
    void compute_v_4(const date&date1);

};
bool checknamnhuan(int year) {
    if ((year%4==0 && year%100!=0)||year%400==0) {
        return true;
    }
    return false;
}
int dayinmonth(int month,int year) {
    switch (month) {
        case 1:case 3:case 5: case 7:case 8 :case 10:case 12:{
            return 31;
        }
        case 4:case 6:case 9:case 11: {
            return 30;
        }
        case 2 :{
             if (checknamnhuan(year)) {
                return 29;
        }
        return 28;
        }
    }
    return 0;
}
int compute_temp_2(const date&date1) {
    int count=date1.day-1;
    if (date1.year > 1970 ) {
        for(int i=1970;i<date1.year;i++){
            if (checknamnhuan(i)){
                count+=366;
            }
            else {
                count+=365;
            }
        }
        for (int i =1;i<date1.month;i++){
            count+=dayinmonth(i,date1.year);
        }
    }
    else if (date1.year==1970) {
         for (int i =1;i<date1.month;i++){
            count+=dayinmonth(i,date1.year);
        }
    }
    else {
        count = 0;
        for(int i=date1.year+1;i<1970;i++){
            if (checknamnhuan(i)){
                count+=366;
            }
            else {
                 count+=365;
            }
        }
        for (int i =date1.month;i<=12;i++){
            count+=dayinmonth(i,date1.year);
        }
        count = count - date1.day + 1;
    }
    return count;
}
void date::inputdate(){
    date date1;
    // yyyy / MM/dd
    cout <<"nhập yyyy/MM/dd"<<endl;
    cin >>year >> month>>day;
}
void date::outputdate(const date& date1){
    cout <<setfill('0')<< year <<" - "<<setw(2)<<month<<" - "<<setw(2)<<day<< endl;
}
void date::outputdate2(const date& date1) {
    string MMM;
    //MMM / dd / yy
    switch(month) {
        case 1: {
            MMM="Jan";
            break;
        }
        case 2: {
            MMM="Feb";
            break;
        }
        case 3: {
            MMM="Mar";
            break;
        }
        case 4: {
            MMM="Apr";
            break;
        }
        case 5:{
            MMM="May";
            break;
        }
        case 6: {
            MMM="Jun";
            break;
        }
        case 7: {
            MMM="Jul";
            break;
        }
        case 8: {
            MMM="Aug";
            break;
        }
        case 9: {
            MMM="Sep";
            break;
        }
        case 10: {
            MMM="Oct";
            break;
        }
        case 11: {
            MMM="Nov";
            break;
        }
        case 12: {
            MMM="Dec";
            break;
        }
    }
    cout << MMM <<" - " << setfill('0')<<setw(2)<<day<<" - "<<setw(2)<<year/100<<endl;
}
void date::tomorow(const date&date1){
    date result = date1;
    result.day++;
    
    if (result.day > dayinmonth(result.month, result.year)) {
        result.day = 1;
        result.month++;
        if (result.month > 12) {
            result.month = 1;
            result.year++;
        }
    }
    result.outputdate(result);  
}
void date::yesterday(const date&date1) {
    date result = date1;
    result.day--;
    
    if (result.day < 1) {
        result.month--;
        
        if (result.month < 1) {
            result.month = 12;
            result.year--;
        }
        
        result.day = dayinmonth(result.month, result.year);
    }
    result.outputdate(result);

}
void date::increase(const date&date1) {
    int k;
    cin>>k;
    date result=date1;
    for (int i = 1 ;i<=k;i++) {
        result.day++;
    
            if (result.day > dayinmonth(result.month, result.year)) {
                result.day = 1;
                result.month++;
                if (result.month > 12) {
                    result.month = 1;
                    result.year++;
                }
    }
    }
    result.outputdate(result);
}
void date::decrease(const date&date1) {
    int k;
    cin >> k;
    date result=date1;
    for (int i =1;i<=k;i++) {
         result.day--;
    
    if (result.day < 1) {
        result.month--;
        
        if (result.month < 1) {
            result.month = 12;
            result.year--;
        }
        
        result.day = dayinmonth(result.month, result.year);
    }
    }
    result.outputdate(result);
}
void date::compare(const date&date1 , const date&date2) {
    int c;
    if (date1.year!=date2.year) {
        c = date1.year-date2.year;
    }
    else if (date1.month!=date2.month) {
        c= date1.month-date2.month;
    }
    else {
        c=date1.day-date2.day;
    }
    if (c>0) {
        cout <<"date 2 sớm hơn"<<endl;
    }
    else if (c==0) {
        cout <<"cùng date" << endl;
    }
    else {
        cout <<"date 1 sớm hơn " << endl;
    }
}
void date::compute_v_1(const date&date1) {
    int count = date1.day;
    for (int i =1;i<date1.month;i++) {
        count+=dayinmonth(i,date1.year);
    }
    cout << count-1 << endl;
}
void date::compute_v_2(const date&date1) {
    int count=date1.day-1;
    if (date1.year > 1970 ) {
        for(int i=1970;i<date1.year;i++){
            if (checknamnhuan(i)){
                count+=366;
            }
            else {
                count+=365;
            }
        }
        for (int i =1;i<date1.month;i++){
            count+=dayinmonth(i,date1.year);
        }
    }
    else if (date1.year==1970) {
         for (int i =1;i<date1.month;i++){
            count+=dayinmonth(i,date1.year);
        }
    }
    else {
        count = 0;
        for(int i=date1.year+1;i<1970;i++){
            if (checknamnhuan(i)){
                count+=366;
            }
            else {
                 count+=365;
            }
        }
        for (int i =date1.month;i<=12;i++){
            count+=dayinmonth(i,date1.year);
        }
        count = count - date1.day + 1;
    }
    cout << count <<endl;
}
void date::compute_v_3(const date&date1,const date&date2) {
    int count=0;
    if (date1.year > date2.year ) {
        for(int i=date2.year+1;i<date1.year;i++){
            if (checknamnhuan(i)){
                count+=366;
            }
            else {
                count+=365;
            }
        }
        for (int i =1;i<date1.month;i++){
            count+=dayinmonth(i,date1.year);
        }
        for (int i = date2.month;i<=12;i++){
             count+=dayinmonth(i,date2.year);
        }
        count=count - date2.day + date1.day;
        
    }
    else if (date1.year==date2.year) {
        if (date1.month > date2.month) {
            for (int i =date2.month;i<date1.month;i++){
            count+=dayinmonth(i,date1.year);
        }
        count = count + date1.day - date2.day;
        }
        else {
            for (int i =date1.month;i<date2.month;i++){
            count+=dayinmonth(i,date1.year);
        }
        count = count + date2.day - date1.day;
        }
    }
    else {
        for(int i=date1.year+1;i<date2.year;i++){
            if (checknamnhuan(i)){
                count+=366;
            }
            else {
                 count+=365;
            }
        }
        for (int i =date1.month;i<=12;i++){
            count+=dayinmonth(i,date1.year);
        }
        for (int i =1;i<date2.month;i++){
            count+=dayinmonth(i,date2.year);
        }
        count = count + date2.day - date1.day;
    }
    cout << count <<endl;


}
void date::compute_v_4(const date&date1) { 
    int k = compute_temp_2(date1);
    int tmp = k%7;
    if (tmp>7) {
        tmp = tmp-7;
    }
    switch (tmp) {
        case 0 : {
            cout << "Thusday" << endl;
            break;
        }
        case 1 :{
            cout <<"Friday" <<endl;
            break;
        }
        case 2: {
            cout <<"Saturday" << endl;
            break;
        }
        case 3: {
            cout <<"Sunday" << endl;
            break;
        }
        case 4: {
            cout <<"Monday" << endl;
            break;
        }
        case 5 : {
            cout <<"Tuesday" << endl;
            break;
        }
        case 6 : {
            cout <<"Wednesday" << endl;
            break;
        }

    }




}
int main () {
    date date1;
    date date2;
    date1.inputdate();
    date2.inputdate();
    date1.outputdate(date1);
    date1.outputdate2(date1);
    date1.compare(date1,date2);
    date1.tomorow(date1);
    date1.yesterday(date1);
    date1.increase(date1);
    date1.decrease(date1);
    date1.compute_v_1(date1);
    date1.compute_v_2(date1);
    date1.compute_v_3(date1,date2);
    date1.compute_v_4(date1);
    return 0;
}