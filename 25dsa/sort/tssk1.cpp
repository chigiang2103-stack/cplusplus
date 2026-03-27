#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void selectionSort(vector<int>& a) {
    for (int i = 0 ; i < a.size()-1 ;i++) {
        int min_pos=i;
        for (int j = i + 1 ; j < a.size() ;j++) {
            if (a[min_pos] > a[j]) min_pos= j;
        }
        swap(a[i], a[min_pos]);
    }
}

void insertionSort(vector<int>& a) {
   int n = a.size();
   for (int i = 0 ; i < n;i++) {
    int j = i;
    while(j > 0 && a[j] < a[j-1]) {
        swap(a[j],a[j-1]);
        j--;
    }
   }
}

void bubbleSort(vector<int>& a) {
    int n = a.size();
    for (int i = 0 ; i < n;i++) {
        bool swaped= false;
        for (int j = 0 ;j < n -i -1;j++ ) {
            if (a[j] > a[j+1]) {
                swap(a[j],a[j+1]);
                swaped=true;
            }
        }
        if (!swaped) break;
    }
}

void shellSort(vector<int>& a) {
    int n = a.size() ;
    for (int gap = n/2 ; gap>=1 ; gap/=2) {
        for (int i = gap ; i < n;i++ ) {
            int j = i;
            while(j - gap >= 0 && a[j] < a[j-gap]) {
                swap(a[j],a[j-gap]);
                j-=gap;
    }
        }
    }
}

void printArray(const vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << (i == a.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    vector<int> original(n);
    for (int i = 0; i < n; i++) cin >> original[i];

    vector<int> a;

    // Test Selection Sort
    a = original;
    selectionSort(a);
    printArray(a);

    // Test Insertion Sort
    a = original;
    insertionSort(a);
    printArray(a);

    // Test Bubble Sort
    a = original;
    bubbleSort(a);
    printArray(a);

    // Test Shell Sort
    a = original;
    shellSort(a);
    printArray(a);

    return 0;
}