#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int dx[6] = {1,-1,0,0,0,0};
int dy[6] = {0,0,1,-1,0,0};
int dz[6] = {0,0,0,0,1,-1};
int board[102][102][102];
int view[102][102][102];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    
    queue<tuple<int,int,int>> Q;
    int m,n,h; // m 가로, n 세로, h 높이
    cin >> m >> n >> h;
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                fill(view[i][j], view[i][j] + m, -1);
            }
        }
    }

    
    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                cin >> board[i][j][k];
                if (board[i][j][k] == 1){
                    Q.push({i,j,k});
                    view[i][j][k] = 0;
                }
            }
        }
    }
    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        for (int idx = 0; idx < 6; idx++)
        {
            int nz = get<0>(cur) + dz[idx];
            int nx = get<1>(cur) + dx[idx];
            int ny = get<2>(cur) + dy[idx];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) continue;
            if (board[nz][nx][ny] != 0 || view[nz][nx][ny] >= 0) continue;
            view[nz][nx][ny] = view[get<0>(cur)][get<1>(cur)][get<2>(cur)] + 1;
            Q.push({nz,nx,ny});
        }
    }


    // for (int i = 0; i < h; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         for (int k = 0; k < m; k++)
    //         {
    //             cout << view[i][j][k] << " ";
    //         }
    //         cout << "\n";
    //     }
    // }
    int ans = 0;

    for (int i = 0; i < h; i++)
    {
        for (int j = 0; j < n; j++)
        {
            for (int k = 0; k < m; k++)
            {
                if (view[i][j][k] == -1 && board[i][j][k] == 0)
                {
                    cout << -1<< "\n";
                    return 0;
                }
                ans = max(ans, view[i][j][k]);
            }
            // cout << "\n";
        }
        
    }
    cout << ans<<"\n";
    


}