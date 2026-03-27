#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
vector<int>ans(500000);
void mergeSort(vector<int>& a, int left, int right) {
    if (left==right) return;
    int mid = (left + right)/2;
    mergeSort(a,left,mid);
    mergeSort(a,mid+1,right);

    int i = left;
    int j = mid + 1;
    int k = left;
    while (i <= mid && j <= right) {
        if (a[i] <= a[j]) ans[k]=a[i++];
        else ans[k]=a[j++];
        k++;
    }
    while (i <= mid) ans[k++]=a[i++];
    while (j<=right) ans[k++]=a[j++];
    for (int i =left  ; i <=  right;i++) a[i] = ans[i];

}

void quickSort(vector<int>& a, int left, int right) {
    if (left>=right) return;
    int mid = (left+right)/2;
    int pivot = a[mid];
    int k = left;
    for (int i = left ; i <= right;i++) {
        if (a[i] < pivot) ans[k++]=a[i];
    }
    int mid1 = k - 1;
    for (int i = left ; i <= right;i++) {
        if (a[i] == pivot) ans[k++]=a[i];
    }
    int mid2 = k ;
    for (int i = left ; i <= right;i++) {
        if (a[i] > pivot) ans[k++]=a[i];
    }

    for (int i = left; i <= right;i++) a[i]=ans[i];
    quickSort(a,left,mid1);
    quickSort(a,mid2,right);
}
void heapify(vector<int>&a,int n , int id) {
    int l = 2*id + 1;
    int r = 2*id + 2;
    int max_id = id;
    if ( l < n && a[l] > a[max_id] )  max_id = l;
    if ( r < n && a[r] > a[max_id] )  max_id = r;
    if ( max_id != id) {
        swap(a[max_id],a[id]);
        heapify(a,n,max_id);
    }
}
void heapSort(vector<int>& a) {
    int n = a.size();
    for (int i = n-1;i>=0;i--) {
        heapify(a,n,i);  
    }

    for  (int i = n-1 ;i>=1;i--) {
        swap(a[0],a[i]);
        heapify(a,i,0);
    }
}

void printArray(const vector<int>& a) {
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << (i == (int)a.size() - 1 ? "" : " ");
    }
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    if (!(cin >> n)) return 0;
    vector<int> original(n);
    for (int i = 0; i < n; i++) cin >> original[i];

    vector<int> a;

    // 1. Test Merge Sort
    a = original;
    if (n > 0) mergeSort(a, 0, n - 1);
    printArray(a);

    // 2. Test Quick Sort
    a = original;
    if (n > 0) quickSort(a, 0, n - 1);
    printArray(a);

    // 3. Test Heap Sort
    a = original;
    if (n > 0) heapSort(a);
    printArray(a);

    return 0;
}
