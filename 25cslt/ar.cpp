
#include <bits/stdc++.h>
using namespace std;
bool isprime(int x) {
    for (int i =2;i*i <=x;i++) {
        if (x%i==0) return false;
    }
    return x>=2;
}
void findcolprime(int** a, int n ,int m) {
     for (int i=0;i<m;i++) {
        bool flag=true;
        for (int j =0;j<n;j++) {
            if (!isprime(a[j][i])) {
                flag=false;
                break;
            }
        }
        if (flag) cout << i << endl;
    }
}
int summatrix(int**a ,int x1,int y1 ,int x2,int y2) {
    int sum =0;
    for (int i =x1 ; i <=x2;i++) {
        for (int j=y1;j<=y2;j++) {
            sum+=a[i][j];
        }
    }
    return sum;

}
int findsubmatrixsum(int **a,int n,int m ) {
    int X1 , X2,Y1,Y2;
    X1=Y1=0;
    X2=n-1;
    Y2=m-1;
    int res = summatrix(a,X1,Y1,X2,Y2);
    for (int x1=0;x1<n;x1++) {
        for (int x2=x1;x2<n;x2++) {
            for (int y1=0;y1<m;y1++) {
                for (int y2=y1;y2<m;y2++) {
                    if (res < summatrix(a,x1,y1,x2,y2)) {
                        res = summatrix(a,x1,y1,x2,y2);
                    }
                }
            }
        }
    }
    return res;


}
int gcd(int a,int b) {
    a=abs(a);
    b=abs(b);
    if (b >a) swap(a,b);
    while (b!=0) {
        int r = a%b;
        a=b;
        b=r;
    }
    return a;
}
int main () {
    int a[100];
    int n; cin >> n;
    for (int i =0 ; i< n;i++) {
        cin >>a[i];
    }
    int res = a[0];
    for (int i = 1 ;i < n;i++) {
        res = gcd(res,a[i]);
    }
    cout << res << endl;


    for (int i = 0 ; i < n -1;i++) {
        if (a[i] > a[i+1]) cout << "false" << endl;
    }
    
    return 0;

}