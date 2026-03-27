#include<iostream>
#include<fstream>
#include<cstring>
using namespace std;

// câu 1 : 
// void hollowPyramid(int h) {
//     for (int i = 1 ; i <= h;i++) {
//         for (int j = h-i;j>=1;j--) {
//             cout << " " ;
//         }
//         for (int k = 1 ; k<=2*(i-1)+1;k++) {
//             if (i!=1 && i!=h) {
//                 if (k==1 ||  k == 2*(i-1)+1) {
//                     cout <<"*";
//                 }
//                 else {
//                     cout <<" ";
//                 }
//             }
//             else {
//                 cout <<"*";
//             }
//         }
//         cout << endl;

//     }
// }
// câu 1 :
// 2 5 3 6 3 
// câu 2 : 

// int* kthLargestSubarray(int a[], int n, int b, int &subSize) {
//     int N = 0 ;
//     for (int i = 1 ; i <= n ; i++) {
//         N+=i;
//     }
//     if (b > N  ) {
//         subSize=0;
//         return NULL;
//     }
//     int *arr = new int[N];
//     int k = 0;
//         for (int i = 0 ; i < n ; i++) {
//             int temp = 0;
//             temp +=a[i];
//             arr[k]= temp;
//             k++;
//             for (int j = i + 1;j<n;j++) {
//                 temp+=a[j];
//                 arr[k]= temp;
//                 k++;
//         } 
//     }
//     for (int i=0; i < N -1 ; i++) {
//         for (int j = i+1;j<N;j++) {
//             if (arr[i] < arr[j]) {
//                 swap(arr[i], arr[j]);
//             }
//         }
//     }
//     int target = arr[b-1];
//     delete [] arr;
//         for (int i = 0 ; i < n ; i++) {
//             int temp = 0;
//             temp +=a[i];
//             if (temp==target) {
//                     subSize =  1;
//                     int *res  = new int[subSize];
//                     for (int m = 0 ; m < subSize;m++) {
//                         res[m] = a[m+i];
//                     }
//                     return res;
//                 }
//             for (int j = i + 1;j<n;j++) {
//                 temp+=a[j];
                
//                 if (temp==target) {
//                     subSize = j - i + 1;
//                     int *res  = new int[subSize];
//                     for (int m = 0 ; m < subSize;m++) {
//                         res[m] = a[m+i];
//                     }
//                     return res;
//                 }
//         } 
//     }
//     return NULL;




// }

//câu 3 : 
void totalRevenue(const char* filename) {
    
    ifstream fin(filename);
    ofstream fout("output.txt");
    if (!fin.is_open()) return ;
    char cate[100][100];
    int num[100];
    int cost[100];
    char line[100];
    int index = 0;
    while (fin.getline(line,100)) {
        strcpy(cate[index],strtok(line,"|"));
        num[index] = atoi(strtok(NULL,"|"));
        cost[index] = atoi(strtok(NULL,"|"));
        index++;
    }
    int sum = 0 ;

    for (int i = 0 ; i < index ; i++) {
        sum+= num[i]*cost[i];
    }

    cout << sum << endl;

    for (int i = 0 ; i < index -1; i++) {
        for (int j = i + 1;j< index ; j++) {
            if (!strcmp(cate[i], cate[j])) {
                num[i]++;
                index--;
            }
        }
    }
    for (int i = 0 ; i < index ; i++) { 
        cout << cate[i] << ":" << num[i] << "ly" << endl;
    }
    int doanhthu[100];
    for (int i = 0 ; i < index ; i++) {
        doanhthu[i] = num[i]*cost[i];
    }
    int max = doanhthu[0];
    int indexmax = 0;
    for (int i = 1 ; i < index;  i++) {
        if (max < doanhthu[i]) {
            max = doanhthu[i];
            indexmax =i ;
        }
    }
    cout << "doanh thu cao nhất : " << cate[indexmax] << " " << max << endl; 

     for (int i = 0 ; i < index ; i++) {
        if (num[i] >= 2) {
            cout << cate[i] << " " << num[i] << " " << cost[i] << " " << doanhthu[i] << endl;
        }
    }
    for (int i = 0 ; i < index -1; i++) {
        for (int j = i + 1;j< index ; j++) {
            if (doanhthu[i] < doanhthu[j]) {
                swap(doanhthu[i], doanhthu[j]);
            }
        }
    }
     for (int i = 0 ; i < index ; i++) {
        fout << cate[i] << " " << num[i] << " " << cost[i] << " " << doanhthu[i] << endl;
    }




    fout.close();
    fin.close();



    

}



int main() {
    totalRevenue("bill.txt");


    return 0;
}

