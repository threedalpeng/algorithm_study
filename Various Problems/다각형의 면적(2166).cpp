#include <iostream>
#include <iomanip>
#include <vector>
using namespace std;

typedef struct _Vector2
{
    double x;
    double y;
} Vector2;
typedef Vector2 Dot;

double cross_product(const Vector2 a, const Vector2 b)
{
    return (a.x * b.y) - (b.x * a.y);
}

int main()
{
    int N;
    cin >> N;

    Dot d1;
    cin >> d1.x >> d1.y;
    
    vector<Vector2> v;
    Dot d_input;
    for (int i = 1; i < N; i++)
    {
        cin >> d_input.x >> d_input.y;
        v.push_back({d_input.x - d1.x, d_input.y - d1.y});
    }

    double area = 0;
    for (int i = 1; i< N; i++)
    {
        area += (cross_product(v[i-1], v[i]) / 2.0);
    }

    cout << fixed << setprecision(1) << (area > 0 ? area : -area) << endl;
}