#include<bits/stdc++.h>
using namespace std;

class color { // tạo lớp color 
    protected:
    string tenmau , mamau  ;
    public :
    color() {  // hàm khởi tạo không tham số 
        tenmau = mamau = "";
    }
    //
    color (string  tenmau , string mamau) { // hàm khởi tạo có tham số
        this->tenmau = tenmau;
        this->mamau = mamau;
    }
    //
    ~color (){ // hàm huỷ 
        tenmau= mamau="";
    }
    //
    friend istream &operator >> (istream& is , color&obj)  { 
        // nạp chồng 
        // tham chiếu istream = is 
        // tham chiếu color = obj 
        cout <<"nhập tên màu : " ;
        fflush(stdin); // khử các dấu cách 
        getline(is , obj.tenmau);

        cout <<"nhập mã màu : "; 
        fflush(stdin); // khử các dấu cách
        getline(is , obj.mamau);
        return is; // return để kết hợp các toán tử >> liên tiếp 
    }; 
    //
    friend ostream &operator << (ostream& os , color& obj) {
        // nạp chồng xuất 
        // tham chiếu ostream = os 
        // tham chiếu color = obj
        os <<"tên màu :" << obj.tenmau << endl;
        os <<"mã màu :" <<obj.mamau << endl;
        return os; // return để kết hợp các toán tử << liên tiếp 

    };
    //
    string gettenmau() { // lấy tên màu 
        return this->tenmau;
    }
    //
};
class point { // khởi tạo lớp point 
    protected:
    int x , y ;
    public :
    point() { // hàm khởi tạo không tham số 
        x=y=0;
    }
    //
    point(int x , int y ) {  // hàm khởi tạo có tham số
        this->x =x;
        this->y = y;
    }
    //
    ~point(){ // hàm huỷ 
        x=y=0;
    }
    //
    friend istream &operator >> (istream&is , point&obj){
        // nạp chồng 
        // tham chiếu istream = is 
        // tham chiếu point= obj 
        cout <<"input x :";
        is >> obj.x;
        cout <<"input y : ";
        is >> obj.y;
        return is;
    };
    friend ostream &operator << (ostream&os , point&obj) {
        // nạp chồng xuất 
        // tham chiếu istream = is 
        // tham chiếu point = obj 
        os <<"x : "<< obj.x <<endl;
        os <<"y : "<<obj.y << endl;
        return os;
    };
    //
    bool check() { // check chéo chính 
        if (x==y) return true;
        return false;
    }
};
//

class pixel : public color , public point { // tạo lớp pixel con của class và point
    public:
    pixel(){// hàm khởi tạo không tham số 
        tenmau = mamau = "";
        x=y=0;
    }
    //
    pixel(int x , int y  ,string tenmau , string mamau){ // hàm khởi tạo có tham số 
        this->tenmau=tenmau;
        this->mamau =mamau;
        this->x = x;
        this->y = y;
    }
    //
    ~pixel(){ // hàm hủy
        tenmau = mamau = "";
        x=y=0;
    }
    //
    friend istream &operator >> (istream&is , pixel&obj){
        cout <<"nhập tenmau :"; fflush(stdin); getline(is,obj.tenmau);
        cout <<"nhập mamau :"; fflush(stdin); getline(is,obj.mamau);
        cout <<"nhập x :"; is>>obj.x; 
        cout <<"nhập y :"; is >>obj.y;
        return is;
    };
    //
    friend ostream &operator << (ostream&os ,pixel&obj) {
        os <<"tenmau : "<< obj.tenmau << endl;
        os <<"mamau : "<< obj.mamau << endl;
        os <<"x :" << obj.x <<endl;
        os <<"y : " << obj.x << endl;
        return os;
    };
    bool check() {
        if (x==y ) {
            return true;
        }
        else if (tenmau == "xanh") {
            return true;
        }
        else return false;
    }

};
int main() {
    int n ; 
    cout << "nhập số lượng phần tử : "; cin >>n;
    pixel* arr = new pixel[n]; // tạo con trỏ theo lớp pixel chứa n phần tử
    for (int i = 0 ;i < n ; i++) {
        cin >> arr[i];
    }
    cout << "output :" << endl;
    for (int i=0 ;i <n;i++) {
        if (arr[i].check()==true) {
            cout << arr[i];
        }
    }
    return 0;



}