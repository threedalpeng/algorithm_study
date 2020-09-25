// 토마토
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

typedef struct 
{
    int r;
    int c;
} Coor;
Coor drt[4] = 
{
    {1, 0},
    {0, 1},
    {-1, 0},
    {0, -1}
};
int M, N, n_bfs = 0;
vector<vector<int>> v;
queue<Coor> q;

bool is_inside(Coor dst)
{
    return ((0 <= dst.r) && (dst.r < N)
        && (0 <= dst.c) && (dst.c < M)
        && (v[dst.r][dst.c] == 0));
}

void BFS()
{
    int size = q.size();
    while(!q.empty())
    {
        for(int i = 0; i < size; i++)
        {
            Coor coor = q.front();
            q.pop();
            for (int j = 0; j < 4; j++)
            {
                Coor dst = {coor.r + drt[j].r, coor.c + drt[j].c};
                if (is_inside(dst))
                {
                    q.push(dst);
                    v[dst.r][dst.c] = 1;
                }
            }
        }
        ++n_bfs;
        size = q.size();
    }
    --n_bfs;
}

int main()
{
    cin.tie(NULL); cout.tie(NULL);
    ios::sync_with_stdio(false);
    cin >> M >> N;
    for (int i = 0; i < N; i++)
    {
        vector<int> tempv(M);
        for (int j = 0; j < M; j++) 
        {
            cin >> tempv[j];
            if (tempv[j] == 1)
            {
                q.push({i, j});
            }
        }
        v.push_back(tempv);
    }

    BFS(); 
    for(auto i : v)
    {
        for(auto j : i)
            if (j == 0)
            {
                n_bfs = -1;
                break;
            }
        if (n_bfs == -1)
            break;
    }
    
    cout << n_bfs;
}