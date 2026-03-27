#include <iostream>
#include <vector>

using namespace std;

vector<int>ans(100005);
void quickSort(vector<int>& a, int low, int high) {
    if (low >= high) return ;
    int pivot = a[(low + high)/2];
    int k = low;
    for (int i = low ; i <=high ;i++) {
        if (a[i] < pivot) ans[k++] = a[i];
    }
    int pivot_1 = k -1;
    for (int i = low ; i <=high ;i++) {
        if (a[i] == pivot) ans[k++] = a[i];
    }
    int pivot_2 = k;
    for (int i = low ; i <=high ;i++) {
        if (a[i] > pivot) ans[k++] = a[i];
    }
    for (int i = low ; i <=high ;i++) {
        a[i] = ans[i];
    }
    quickSort(a,low,pivot_1);
    quickSort(a,pivot_2,high);

}


int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    if (n <= 0)
        return 0;

    vector<int> vals(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> vals[i];
    }
    quickSort(vals,0,n-1);

    int result = vals[0];
    int cnt =1;
    int cur = 1;
    for (int i = 0 ; i < n-1;i++) {
       
        if (vals[i] == vals[i+1]) {
            cur++;
        }
        else {
            if (cur > cnt) {
                cnt =cur;
                result = vals[i];
            }
            cur = 1;
        }
    }

    cout << result;
    return 0;
}