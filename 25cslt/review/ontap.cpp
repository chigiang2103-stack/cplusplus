#include <bits/stdc++.h>
using namespace std;

// Query 1
void queryPrintDigits(long long n) {
    int arr[100];
    int len = 0 ;
    while (n!=0) {
        arr[len]=n%10;
        n=n/10;
        len++;
    }
    for (int i = len -1; i>=0;i--) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

// Query 2
long long queryReverseNumber(long long n) {
    long long num = 0;
    while(n!=0) {
        num=num*10 + n%10;
        n=n/10;
    }
    return num;
}

// Query 3
long long queryReverseSegment(long long n, int l, int r) {
    int arr[100];
    int len = 0 ;
    while (n!=0) {
        arr[len]=n%10;
        n=n/10;
        len++;
    }
    long long num = 0;
    int j = l -1 ;
    for (int i = len -1; i>=0;i--) {
        if(i >= l-1 && i <= r -1) {
            num = num*10 + arr[j];
            j++;
        }
        else {
            num = num*10 +  arr[i];
        }
    }
    return num;

}

// Query 4
long long queryDeleteKthDigit(long long n, int k) {
    int arr[100];
    int len = 0 ;
    while (n!=0) {
        arr[len]=n%10;
        n=n/10;
        len++;
    }
    long long num = 0;
    for (int i = len -1 ; i >=0;i--) {
        if (i!=len -k) {
            num = num*10 + arr[i];
        }
    }
    return num;
}

// Query 5
long long queryDeleteDigit(long long n, int digit) {
    int arr[100];
    int len = 0 ;
    while (n!=0) {
        arr[len]=n%10;
        n=n/10;
        len++;
    }
    long long num = 0;
    for (int i = len -1 ; i >=0;i--) {
        if (arr[i]!=digit) {
            num = num*10 + arr[i];
        }
    }
    return num;
}

// Query 6
long long queryInsertDigit(long long n, int k, int digit) {
    int arr[100];
    int len = 0 ;
    while (n!=0) {
        arr[len]=n%10;
        n=n/10;
        len++;
    }
    long long num = 0;
    bool flag = true;
    for (int i = len -1 ; i >=0;i--) {
        if (i!= len - k) {
            num = num*10 + arr[i];
        }
        else {
            if (flag) {
                num = num*10 + digit;
                i=i+1;
                flag = false;
            }
            else {
                num = num*10 + arr[i];
            }
        }
    }
    return num;
}
// Query 7
void queryPrimeFactorization(long long n) {
    for (int i = 2; i<=sqrt(n);i++) {
        int mu = 0;
        if (n%i==0) {
            while (n%i==0) {
            mu++;
            n=n/i;
        }
        cout << i <<"^"<<mu << " ";
        }
    }
    cout << n <<"^"<<1;
    cout << endl;
}

// Query 8
long long queryOddBeforeEven(long long n) {
    int arr[100];
    int len = 0 ;
    while (n!=0) {
        arr[len]=n%10;
        n=n/10;
        len++;
    }
    long long num = 0;
    for (int i = len -1 ; i >=0;i--) {
        if (arr[i]%2==1) {
            num=num*10 + arr[i];
        }
    }for (int i = len -1 ; i >=0;i--) {
        if (arr[i]%2==0) {
            num=num*10 + arr[i];
        }
    }
    return num;
}

// Query 9
long long queryMaxReorder(long long n) {
    int arr[100];
    int len = 0 ;
    while (n!=0) {
        arr[len]=n%10;
        n=n/10;
        len++;
    }
    long long num = 0;
    for (int i = len-1 ; i>=1;i--) {
        for (int j = i -1;j>=0;j--) {
            if (arr[j] > arr[i]) {
                swap(arr[i],arr[j]);
            }
        }
        num=num*10 + arr[i];
    }
    return num;
}

// Query 10
long long queryInterleave(long long n, long long m) {
    int arr1[100];
    int len_n = 0 ;
    while (n!=0) {
        arr1[len_n]=n%10;
        n=n/10;
        len_n++;
    }
    int arr2[100];
    int len_m = 0 ;
    while (m!=0) {
        arr2[len_m]=m%10;
        m=m/10;
        len_m++;
    }
    long long num=0;
    if (len_n >= len_m) {
        for (int i = len_m -1; i >=0 ; i--) {
            num=num*10 + arr1[len_n-1];
            num=num*10 + arr2[i];
            len_n--;
        }
        for (int j = len_n-1;j>=0;j--) {
            num = num*10 + arr1[j];
        }
    }
    else {
        for (int i = len_n-1 ; i >=0 ; i--) {
            num=num*10 + arr1[i];
            num=num*10 + arr2[len_m-1];
            len_m--;
        }
        for (int i = len_m-1;i>=0;i--) {
            num = num*10 + arr2[i];
        }
    }
    return num;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q; 
    cin >> q;
    while(q--){
        int type; 
        cin >> type;
        if(type == 1){
            long long n; 
            cin >> n;
            queryPrintDigits(n);
        }
        else if(type == 2){
            long long n; 
            cin >> n;
            cout << queryReverseNumber(n) << endl;
        }
        else if(type == 3){
            long long n; 
            int l, r;
            cin >> n >> l >> r;
            cout << queryReverseSegment(n, l, r) << endl;
        }
        else if(type == 4){
            long long n; 
            int k;
            cin >> n >> k;
            cout << queryDeleteKthDigit(n, k) << endl;
        }
        else if(type == 5){
            long long n; 
            int d;
            cin >> n >> d;
            cout << queryDeleteDigit(n, d) << endl;
        }
        else if(type == 6){
            long long n; 
            int k, d;
            cin >> n >> k >> d;
            cout << queryInsertDigit(n, k, d) << endl;
        }
        else if(type == 7){
            long long n; 
            cin >> n;
            queryPrimeFactorization(n);
        }
        else if(type == 8){
            long long n; 
            cin >> n;
            cout << queryOddBeforeEven(n) << endl;
        }
        else if(type == 9){
            long long n; 
            cin >> n;
            cout << queryMaxReorder(n) << endl;
        }
        else{
            long long n, m; 
            cin >> n >> m;
            cout << queryInterleave(n, m) << endl;
        }
        if (q) cout << "=====" << endl;
    }
    return 0;
}