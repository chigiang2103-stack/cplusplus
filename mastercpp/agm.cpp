#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstring>
using namespace std;

struct Point {
    double x, y;
};

struct Triangle {
    Point A, B, C;
};

// TODO: Viết hàm nhập tọa độ 1 điểm
void inputPoint(Point &p) {
    cin >> p.x >> p.y;
}

// TODO: Viết hàm tính khoảng cách giữa 2 điểm
double distance(Point p1, Point p2) {
    return sqrt((p2.x - p1.x)*(p2.x - p1.x) + (p2.y-p1.y)*(p2.y-p1.y));
}

// TODO: Viết hàm nhập thông tin tam giác
void inputTriangle(Triangle &t) {
    Point A;
    Point B;
    Point C;
    inputPoint(t.A);
    inputPoint(t.B);
    inputPoint(t.C);
}

// TODO: Viết hàm tính chu vi tam giác
double perimeter(const Triangle &t) {
       return distance(t.A,t.B) + distance(t.B,t.C) + distance(t.A,t.C);
}

// TODO: Viết hàm tìm trọng tâm tam giác
Point centroid(const Triangle &t) {
    Point g = {0, 0};
    g.x = (t.A.x + t.B.x +t.C.x)/3;
    g.y = (t.A.y + t.B.y + t.C.y)/3;
    return g;
}

// TODO: Viết hàm in kết quả
void printResult(const Triangle &t) {
   cout << "Perimeter: "<< fixed << setprecision(2)<< perimeter(t) << endl;
   cout << "Centroid: " << fixed << setprecision(2) << "(" << centroid(t).x << ", "<<centroid(t).y<<")" << endl;
}

int main() {
    Triangle t;
    inputTriangle(t);
    printResult(t);
    return 0;
}

