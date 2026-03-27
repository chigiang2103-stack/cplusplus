#include<iostream>
#include<fstream>
using namespace std;

int main () {
        int choice ;

    do {
        
        cout << "MENU" << endl;
        cout << 1 << ". Enter array " << endl;
        cout << 2 << ". Loads array " << endl;
        cout << "Lựa chọn 1 trong 2 tính năng :  " << endl;
        cin >> choice;
        switch (choice) {
            case 1 : {
                ofstream fout("output_2.1.bin" , ios::binary); 
                if (!fout) {
                    cout <<"không đọc được file! " << endl;
                    break;
                }

                int num ;
                cout << "Số phần tử : " ;;
                cin >> num;
                int *arr = new int[num];
                cout << "Nhập các phần tử của mảng : "<<endl;
                for (int i = 0 ; i<num;i++) {
                    cin >> arr[i];
                }
                fout.write((char*)(&num) , sizeof(num));
                fout.write((char*)arr , num*sizeof(arr[0]));
                fout.close();
                break;

            }
            case 2 : {
                ifstream fin("input_2.1.bin", ios::binary);
                  if (!fin) {
                    cout <<"không đọc được file! " << endl;
                    break;
                }
                int num ;
                fin.read((char*) (&num) , sizeof(num));
                int *arr = new int[num];
                fin.read((char*)arr , num*sizeof(arr[0]));
                for (int i=0;i<num-1;i++) { 
                    for (int j = i +1 ; j< num ;j++) {
                        if (arr[i] > arr[j]) {
                            swap(arr[j] , arr[i]);
                        }
                    }
                }
                double tv ;
                if (num%2==1) {
                    tv =arr[num/2 ];
                    cout << "Trung vị : " <<tv<< endl;
                }
                else {
                    tv = (arr[num/2-1] + arr[num/2])/2.0;
                    cout <<"Trung vị : " << tv << endl;
                }


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