#include<iostream>
#include<fstream>
using namespace std;


const int SELL_TICKER = 1;
const int THONG_KE  = 2;
const int TOTAL_MONEY = 3;
const int OUT = 4;

void initialize_system(char **seat , int M ,int N) {
    for (int i = 0 ;i<M;i++) {
        for (int j =0;j<N;j++) {
            seat[i][j]='#';
        }
    }
}




void display(char **seat , int M ,int N ) {
    cout << "======================================================" << endl;
    cout <<"\t \t Seats";
    cout << endl;
    cout <<"\t";
    for (int i =1 ;i<=N;i++) {
        cout  << i%10;
    }
    cout << endl;
    for (int i= 0;i<M;i++) {
        cout <<"ROW  " <<i+1 << "\t";
        for (int j=0;j<N;j++) {
            cout << seat[i][j] ;
        }
        cout << endl << endl;
    }
}

void sell_ticker(char** seat , int M ,int N ,int &total,int*cost) {
    int row , chair ;
    cout << "Nhập số hàng : "; cin >> row;
    cout << "Nhập số ghế : "; cin >> chair;
    if (row < 0 || row > 15 || chair < 0 || chair > 30) {
        cout <<"không hợp lệ! " << endl;
        return;
    }

    if(seat[row][chair] == '*') {
        cout <<"ghế đã bán! vui lòng chọn lại";
        sell_ticker(seat , M ,N , total,cost);  
    }
    if (seat[row-1][chair-1] == '#') {
        seat[row-1][chair-1] ='*';
        cout <<"đặt chổ thành công! " << endl;
        total += *(cost + row-1); 
            int choice ;
            cout <<"Để đặt thêm vé vui lòng chọn : 1" << endl;
            cout <<"Hoặc chọn 0 để kết thúc!" << endl;
            cin >> choice ;
            if (choice) {
                sell_ticker(seat , M ,N , total,cost);  
            }
            else {
                cout <<"Tổng tiền : "<<total << endl;;
            }
        
    }
}

void show_statist(char** seat , int M ,int N ) {
    int total_sold =0;
    for (int i = 0 ;i<M;i++) {
        for (int j =0;j<N;j++) {
                if (seat[i][j]=='*') 
                    {
                      total_sold++;
                    }
                }
            }
    cout << "Số vé đã bán : "<<total_sold<<endl;

    int total_empty=0;
    for (int i = 0 ;i<M;i++) {
        for (int j =0;j<N;j++) {
                if (seat[i][j]=='#') 
                    {
                      total_empty++;
                    }
                }
            }
    cout << "Số vé còn trống bán : "<<total_empty<<endl;

    for(int i= 0;i<M;i++) {
        int count=0;
        for(int j =0;j<N;j++) {
            if (seat[i][j]=='#') {
                count++;
            }
        }
        cout <<"số vé trống hàng "<<i+1<<" : "<<count<<endl;
    }

}




int main () {
    int M = 15 , N = 30;


    char **seat = new char *[M];
    for (int i =  0 ;i<M;i++) {
        seat[i] = new char[N];
    } 


    int *cost = new int[M];

    ifstream fin("input.txt");
    int i=0;

    while (!fin.eof() && i<M){
        int n; 
        fin >> n;
        *(cost + i) = n;
        i++;
        if (n==0) break;
    }


    initialize_system(seat,M,N);


    display(seat,M,N);

    int total =0;

    sell_ticker(seat ,M ,N , total , cost);







    int choice ;
    do {
        cout << "\n-- MENU --" << endl;
        cout << SELL_TICKER<< ". Mua vé" << endl;
        cout << THONG_KE << ". Thống kê " << endl;
        cout << TOTAL_MONEY << ". TỔNG TIỀN" << endl;
        cout << OUT << ". Thoat (Out)" << endl;
        cout << "Chon chuc nang: ";
        cin >> choice;
        int user_id, lab_num, station_num; 
        switch(choice) {
            case SELL_TICKER : {
                sell_ticker(seat,M,N,total,cost);
            break;
            }
            case THONG_KE : {
                show_statist(seat,M,N);
                break;
            }
            case TOTAL_MONEY : {
                 cout <<"Tổng tiền : "<<total << endl;;
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
            delete[] seat[i];
        }
        delete[] seat;


    fin.close();





    return 0;
}