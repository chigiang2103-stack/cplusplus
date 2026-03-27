#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    int arr[n];
    for (int i = 0 ;i<n;i++) {
        cin >> arr[i];
    }
    int min;
    int max;
    bool flag_chẳn = false;
    bool flag_lẻ=false;
    for (int i = 0;i<n;i++) {
        if(arr[i]%2==0){
            if (flag_chẳn==false){
                max = arr[i];
                flag_chẳn=true;
            }
            else if (max < arr[i]) {
                max = arr[i];
            }
        }
        else {
            if (flag_lẻ==false) {
                min=arr[i];
                flag_lẻ=true;
            }
            else if (min > arr[i]) {
                min=arr[i];
            }
        }
    }
    if (flag_chẳn) {
        cout <<max;
    }
    else {
        cout <<-1;
    }
    cout <<" ";
    if (flag_lẻ){
        cout << min;
    }
    else {
        cout << -1;
    }
    cout << endl;

    return 0;
}