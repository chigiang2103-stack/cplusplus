#include<iostream>
#include<fstream>
using namespace std;

struct dates {
    int day , month , year;
};
bool isNewer(dates d1, dates d2) {
    if (d1.year != d2.year) return d1.year > d2.year;
    if (d1.month != d2.month) return d1.month > d2.month;
    return d1.day > d2.day;
}
int main () {
        int choice ;

    do {
        
        cout << "MENU" << endl;
        cout << 1 << ". Enter array of dates " << endl;
        cout << 2 << ". Loads array of dates" << endl;
        cout << "Lựa chọn 1 trong 2 tính năng :  " << endl;
        cin >> choice;
        switch (choice) {
            case 1 : {
                ofstream fout("output_2.2.bin" , ios::binary); 
                if (!fout) {
                    cout <<"không đọc được file! " << endl;
                    break;
                }

                int num ;
                cout << "Số phần tử : " ;;
                cin >> num;
                dates *arr = new dates[num];
                cout << "Nhập các phần tử của mảng theo form ngày - tháng - năm : "<<endl;
                for (int i = 0 ; i<num;i++) {
                    cin >> arr[i].day >> arr[i].month >> arr[i].year ;
                }
                fout.write((char*)(&num) , sizeof(num));
                fout.write((char*)arr , num*sizeof(arr[0]));
                fout.close();
                break;

            }
            case 2 : {
                ifstream fin("output_2.2.bin", ios::binary);
                  if (!fin) {
                    cout <<"không đọc được file! " << endl;
                    break;
                }
                int num ;
                fin.read((char*) (&num) , sizeof(num));
                dates *arr = new dates[num];
                fin.read((char*)arr , num*sizeof(arr[0]));
                dates ans = arr[0];
                for (int i = 1 ; i<num ;i++) {
                    if (!isNewer(ans , arr[i])) {
                        ans = arr[i];
                    }
                }
                cout << ans.day <<" "<< ans.month<<" " << ans.year << endl;


                fin.close() ;
                delete [] arr;

            break;
            }
            default : {
                cout <<"không hợp lệ!" << endl;
            }
        }




    }
    while (choice!=1 && choice !=2);


    return 0;
}