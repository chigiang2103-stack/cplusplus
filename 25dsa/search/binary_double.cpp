#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>
#include<math.h>


using namespace std;

double f(double x) {
    return x*x + sqrt(x) ;
}

int main () {
   double c; cin >> c;
   double l = 0 ;
   double r = 1e8;
   while (r-l >1e-8) {
        double mid = (l+r)/2;
        if (f(mid) < c) l = mid;
        else r=mid;
   }
   cout << setprecision(6) << fixed;
    cout << l;
   



    return 0;
}