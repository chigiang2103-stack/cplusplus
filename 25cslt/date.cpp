#include <bits/stdc++.h>
using namespace std;

struct Date {
    int d, m, y;
};

// Kiểm tra năm nhuận
bool isLeap(int y) {
    return (y%4==0 && y%100!=0) || y%400==0 ;
}
// Số ngày trong tháng m của năm y
int daysInMonth(int m, int y) {
    switch(m) {
        case 1 : case 3 : case 5 : case 7 : case 8 : case 10 : case 12 : {
            return 31;
        }
        case 4 : case 6 : case 9 : case 11 : {
            return 30;
        }
        case 2 : {
            if (isLeap(y)) {
                return 29;
            }
            return 28;
        }
    }
    return 0;
}

// So sánh hai ngày, trả về true nếu a < b
bool isBefore(const Date& a, const Date& b) {
    if (a.y > b.y) {
        return false; 
    }
    else if (a.y < b.y) return true;
    else {
        if (a.m > b.m) return false;
        else if (a.m < b.m ) return true;
        else {
            if (a.d >= b.d ) return false;
            else return true;
        }
    }
}

// Cộng k ngày vào ngày a
Date addDays(Date a, int k) {
    for (int i = 1 ; i <=k ;i++) {
        if (a.d != daysInMonth(a.m , a.y)) {
            a.d++;
        }
        else {
            if (a.m!=12) {
                a.m++;
                a.d=1;
            }
            else {
                a.y++;
                a.m = 1;
                a.d=1;
            }
        }
    }
    return a;
}

// Trừ k ngày khỏi ngày a
Date subDays(Date a, int k) {
    for (int i =1;i<=k;i++) {
        if (a.d!=1) {
            a.d--;
        }
        else {
            if (a.m!=1) {
                a.m--;
                a.d=daysInMonth(a.m,a.y);
                
            }
            else {
                a.y--;
                a.m=12;
                a.d=31;
            }
        }

    }
    return a;
}

// Khoảng cách tuyệt đối (số ngày) giữa hai ngày
int distanceDays(Date a, Date b) {
    int d_m_b = b.d;
    for (int i = 1;i<b.m;i++) {
        d_m_b+=daysInMonth(i,b.y);
    }
    for (int i = 1; i< b.y;i++) {
        if (isLeap(i)) {
            d_m_b+=366;
        }
        else {
            d_m_b+=365;
        }
    }
    int d_m_a = a.d;
    for (int i = 1;i<a.m;i++) {
        d_m_a+=daysInMonth(i,a.y);
    }
      for (int i = 1; i< a.y;i++) {
        if (isLeap(i)) {
            d_m_a+=366;
        }
        else {
            d_m_a+=365;
        }
    }
   
    return abs(d_m_a-d_m_b);
}
bool isPrime(int x) {
    for (int i = 2 ; i*i <= x ;i++) {
        if (x%i==0) return false;
    }
    return x >= 2;
}
// Đếm số ngày trong đoạn [a, b] sao cho d + y là số nguyên tố
int countPrimeDY(Date a, Date b) {
    if (isBefore(b, a)) swap(a, b);
    int count = 0;
    Date date_temp = a;
    for (int i = 1 ; i <= distanceDays(a,b) +1 ; i++) {
        if (isPrime(date_temp.d + date_temp.y)) {
            count++;
        }
        date_temp = addDays(date_temp,1);
    }
    return count ;
}
// Biết weekday(a) = k (1..7), tìm weekday(b)
int weekdayFromKnown(Date a, Date b, int k) {
    int dis = distanceDays(a,b);
    int res = (dis +k -1)%7 +1;
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int q;
    cin >> q;
    while (q--) {
        int type;
        cin >> type;
        if (type == 1) {
            Date a, b;
            cin >> a.d >> a.m >> a.y >> b.d >> b.m >> b.y;
            cout << (isBefore(a, b) ? "YES" : "NO") << endl;
        } else if (type == 2) {
            Date a; int k;
            cin >> a.d >> a.m >> a.y >> k;
            Date r = addDays(a, k);
            cout << r.d << " " << r.m << " " << r.y << endl;
        } else if (type == 3) {
            Date a; int k;
            cin >> a.d >> a.m >> a.y >> k;
            Date r = subDays(a, k);
            cout << r.d << " " << r.m << " " << r.y << endl;
        } else if (type == 4) {
            Date a, b;
            cin >> a.d >> a.m >> a.y >> b.d >> b.m >> b.y;
            cout << distanceDays(a, b) << endl;
        } else if (type == 5) {
            Date a, b;
            cin >> a.d >> a.m >> a.y >> b.d >> b.m >> b.y;
            cout << countPrimeDY(a, b) << endl;
        } else if (type == 6) {
            Date a, b; int k;
            cin >> a.d >> a.m >> a.y >> b.d >> b.m >> b.y >> k;
            cout << weekdayFromKnown(a, b, k) << endl;
        }
    }
    return 0;
}