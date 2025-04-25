#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
string board[102];
int view1[102][102];
int view2[102][102];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    int first = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (view1[i][j] == 0){
                first++;
                char alpha = board[i][j];
                queue<pair<int,int>> Q;
                Q.push({i,j});
                view1[i][j] = 1;
                while (!Q.empty())
                {
                    auto cur = Q.front(); Q.pop();
                    for (int idx = 0; idx < 4; idx++)
                    {
                        int nx = cur.first + dx[idx];
                        int ny = cur.second + dy[idx];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (board[nx][ny] != alpha || view1[nx][ny] == 1) continue;
                        Q.push({nx,ny});
                        view1[nx][ny] = 1;
                    }
                }
            }
        }
    }

    cout << first << " ";
    

    int second = 0;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (view2[i][j] == 0){
                second++;
                char alpha = board[i][j];
                queue<pair<int,int>> Q;
                Q.push({i,j});
                view2[i][j] = 1;
                while (!Q.empty())
                {
                    auto cur = Q.front(); Q.pop();
                    for (int idx = 0; idx < 4; idx++)
                    {
                        int nx = cur.first + dx[idx];
                        int ny = cur.second + dy[idx];
                        if (nx < 0 || nx >= n || ny < 0 || ny >= n) continue;
                        if (view2[nx][ny] == 1) continue;
                        if (alpha == 'B'){
                            if (board[nx][ny] != 'B'){
                                continue;
                            }
                        }
                        else { // A랑 G
                            if (board[nx][ny] == 'B'){
                                continue;
                            }
                        }
                        Q.push({nx,ny});
                        view2[nx][ny] = 1;
                    }
                }
            }
        }
    }
    cout << second << "\n";
    


}