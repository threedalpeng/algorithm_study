#include <iostream>
using namespace std;
using Point = pair<int, int>;
using Line = pair<Point, Point>;

Point operator-(Point& p1, Point& p2) { return Point(p1.first - p2.first, p1.second - p2.second);}
istream& operator>>(istream& i, Point& p) { i >> p.first >> p.second; return i; }
int operator%(Point p1, Point p2) 
{ 
    return p1.first * p2.second - p2.first * p1.second; 
}
int CCW(Point& p1, Point& p2, Point& p3)
{
    int cross_res = (p2 - p1)%(p3 - p1);
    if (!cross_res) return 0;
    else if (cross_res > 0) return 1;
    else return -1;
}

int main()
{
    Point p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    cout << CCW(p1, p2, p3) << '\n';
}