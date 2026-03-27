#include<iostream>
using namespace std;


const int LOGIN = 1;
const int LOGOFF  = 2;
const int DISPLAY = 3;
const int SEARCH = 4;
const int OUT = 5;

void initialize_system(int **lab , int M ,int N) {
    for (int i = 0 ;i<M;i++) {
        for (int j =0;j<N;j++) {
            lab[i][j]=0;
        }
    }
}


void process_login(int **lab ,int user_id ,int lab_num , int station_num ) {
    lab[lab_num-1][station_num-1]=user_id;
    cout << "User " << user_id << " đã đăng nhập hệ thống thành công! "<< endl;
}

void process_logoff(int**lab , int lab_num , int station_num ){
    lab[lab_num-1][station_num-1]=0;
    cout << "User đã đăng xuất hệ thống thành công! "<<endl;
}


void display(int **lab , int M ,int N ) {
    cout << "Trạng thái lab " << endl;
    cout <<"lab\t";
    for (int i =1 ;i<=N;i++) {
        cout << "S" << i << "\t";
    }
    cout << endl;
    for (int i= 0;i<M;i++) {
        cout << i+1 << "\t";
        for (int j=0;j<N;j++) {
            cout << lab[i][j] << "\t";
        }
        cout << endl << endl;
    }
}
void search_user(int **lab , int M ,int N , int x) {
    bool flag=false;
    for (int i= 0;i<M;i++) {
        for (int j=0;j<N;j++) { 
            if (x == lab[i][j]){
                flag=true;
                cout << "User " << x << " Đang đăng nhập tại lab : "<<i+1 << " và station :  " << j+1 << endl;
            }
        }
    }
    if (flag==false) cout << "None" << endl;
}





int main () {
    int M , N;
    cout << "Nhập số lượng lab : " ; cin >> M;
    cout <<"Nhập số lượng Station : ";cin >> N;
    int **lab = new int *[M];
    for (int i =  0 ;i<M;i++) {
        lab[i] = new int[N];
    } 
    initialize_system(lab,M,N);
    int choice ;
    do {
        cout << "\n-- MENU --" << endl;
        cout << LOGIN << ". Dang nhap (Log On)" << endl;
        cout << LOGOFF << ". Dang xuat (Log Off)" << endl;
        cout << DISPLAY << ". Hien thi trang thai (Display)" << endl;
        cout << SEARCH << ". Tim kiem User (Search)" << endl;
        cout << OUT << ". Thoat (Out)" << endl;
        cout << "Chon chuc nang: ";
        cin >> choice;
        int user_id, lab_num, station_num; 
        switch(choice) {
            case LOGIN : {
                cout << "Nhap ID, Lab, Station"<<endl;
                cin >> user_id >> lab_num >> station_num ;
                if (user_id > 99999 || user_id <10000 || lab_num > M || station_num > N) {
                    cout <<"Không hợp lệ! " << endl;
                    break;
                }
                process_login(lab ,user_id , lab_num , station_num);
                display(lab , M ,N);
                break;
            }
            case LOGOFF : {
                cout << "nhập lab và sation cần đăng xuất : ";
                cin >> lab_num >> station_num ;
                if (lab_num > M || station_num > N){
                    cout << "Không hợp lệ!" << endl;
                    break;
                }
                process_logoff(lab , lab_num , station_num);
                display(lab , M , N);
                break;
            }
            case DISPLAY : {
                display(lab , M , N );
                break;
            }
            case SEARCH : {
                cout << "Nhap ID muon tim: ";
                cin >> user_id;
                search_user(lab, M, N, user_id);
                break;
            }
            case OUT : {
                cout <<"Thoát chương trình! "<<endl;
                break;
            }
            default : {
                cout << "Lựa chọn không hợp lệ! "<< endl;
                break;
            }
        }
    }
    while (choice!=OUT) ;

    for (int i = 0; i < M; i++) {
            delete[] lab[i];
        }
        delete[] lab;





    return 0;
}