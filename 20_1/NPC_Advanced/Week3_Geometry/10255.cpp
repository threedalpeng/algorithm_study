#include <iostream>
using namespace std;
using Point = pair<int, int>;
using Line = pair<Point, Point>;

template<typename T>
istream& operator>>(istream& in, T& a){return in >> a.first >> a.second;}

int main()
{
    int xmin, ymin, xmax, ymax;
    
}