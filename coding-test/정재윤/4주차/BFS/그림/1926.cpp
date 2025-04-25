#include <bits/stdc++.h>

using namespace std;

int board[502][502] = {0};
int view[502][502] = {0};

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n,m;
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }
    int count = 0;
    int max_size = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (board[i][j] == 1 && view[i][j] == 0){
                // cout << "here\n";
                count++;
                int temp_max_size = 0;
                queue<pair<int,int>> Q;
                Q.push({i, j});
                view[i][j] = 1;
                while (!Q.empty())
                {
                    pair<int,int> cur = Q.front(); Q.pop();
                    temp_max_size++; 
                    for (int idx = 0; idx < 4; idx++)
                    {
                        int nx = dx[idx] + cur.first;
                        int ny = dy[idx] + cur.second;
                        if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if (view[nx][ny] == 1 || board[nx][ny] == 0) continue;
                        view[nx][ny] = 1;
                        Q.push({nx, ny});
                        
                    }
                }
                // cout << "max_size : "  << max_size << " temp_max_size : " << temp_max_size << "\n";
                max_size = max(max_size, temp_max_size);
            }   
        }
    }
    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < m; j++)
    //     {
    //         cout <<  view[i][j] << " ";
    //     }
    //     cout << "\n";
    // }
    cout << count << "\n";
    cout << max_size << "\n";
    

    
}