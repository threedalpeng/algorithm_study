// 맥주 마시면서 걸어가기
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

const int INF = 1e9;

class Point
{
public:
    Point(){};
    Point(int _x, int _y) : x(_x), y(_y) {}
    const int operator-(const Point& p) const
    {
        return abs(x - p.x) + abs(y - p.y);
    }
    friend istream& operator>>(istream&, Point&);

private:
    int x = 0;
    int y = 0;
};

istream& operator>>(istream& in, Point& p)
{
    return in >> p.x >> p.y;
}

int n, t;
vector<Point> pts;
bool graph[102][102];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> t;
    while (t--)
    {
        cin >> n;
        pts.resize(n + 2);
        for (int i = 0; i <= n; i++)
        {
            for (int j = i + 1; j <= n + 1; j++)
            {
                graph[i][j] = false;
                graph[j][i] = false;
            }
        }
        int fest = n + 1;
        for (int i = 0; i <= n + 1; i++)
        {
            cin >> pts[i];
        }
        for (int i = 0; i <= n; i++)
        {
            for (int j = i + 1; j <= n + 1; j++)
            {
                int dist = pts[i] - pts[j];
                if (dist <= 1000)
                {
                    graph[i][j] = true;
                    graph[j][i] = true;
                }
            }
        }

        for (int k = 0; k <= n + 1; k++)
        {
            for (int i = 0; i <= n + 1; i++)
            {
                for (int j = 0; j <= n + 1; j++)
                {
                    if (!graph[i][j] && i != j)
                    {
                        if (graph[i][k] && graph[k][j] || graph[j][k] && graph[k][i])
                        {
                            graph[i][j] = true;
                            graph[j][i] = true;
                        }
                    }
                }
            }
        }

        cout << (graph[0][fest] ? "happy" : "sad") << '\n';
    }
}