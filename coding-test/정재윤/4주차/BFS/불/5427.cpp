#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int w,h;
        cin >> w >> h;
        string board[1002];
        int player[1002][1002];
        int fire[1002][1002];
        for (int c = 0; c < h; c++)
        {
            fill(player[c], player[c]+w, -1);
            fill(fire[c], fire[c]+w, -1);
        }
        
        queue<pair<int,int>> play_Q;
        queue<pair<int,int>> fire_Q;

        for (int q = 0; q < h; q++)
        {
            cin >> board[q];
            for (int e = 0; e < w; e++)
            {
                if (board[q][e] == '*'){ // 불 시작 위치 여러개
                    fire_Q.push({q,e});
                    fire[q][e] = 0;
                }
                if (board[q][e] == '@'){
                    play_Q.push({q,e});
                    player[q][e] = 0;
                }
            }
        }

        while (!fire_Q.empty())
        {
            auto cur = fire_Q.front(); fire_Q.pop();
            for (int idx = 0; idx < 4; idx++)
            {
                int nx = cur.first + dx[idx];
                int ny = cur.second + dy[idx];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
                if (board[nx][ny] == '#' || fire[nx][ny] >= 0) continue;
                fire[nx][ny] = fire[cur.first][cur.second] + 1;
                fire_Q.push({nx, ny});
            }
        }
        // cout << "fire---------------\n";
        // for (int pr = 0; pr < h; pr++)
        // {
        //     for (int pr_2 = 0; pr_2 < w; pr_2++)
        //     {
        //        cout << fire[pr][pr_2] << " ";
        //     }
        //     cout << "\n";
        // }
        
        bool escape = false;

        while (!play_Q.empty())
        {
            auto cur = play_Q.front(); play_Q.pop();
            for (int idx = 0; idx < 4; idx++)
            {
                int nx = cur.first + dx[idx];
                int ny = cur.second + dy[idx];
                if (nx < 0 || nx >= h || ny < 0 || ny >= w){ // 이게 탈출한 거임
                    cout << player[cur.first][cur.second] + 1 << "\n";
                    escape = true;
                    break;
                }
                if (board[nx][ny] == '#' || board[nx][ny] == '*' || player[nx][ny] >= 0 || (fire[nx][ny] >= 0 && fire[nx][ny] <= player[cur.first][cur.second] + 1)) continue;
                player[nx][ny] = player[cur.first][cur.second] + 1;
                play_Q.push({nx, ny});
            }
            if (escape == true)
                break;
        }
        // cout << "player---------------\n";
        // for (int pr = 0; pr < h; pr++)
        // {
        //     for (int pr_2 = 0; pr_2 < w; pr_2++)
        //     {
        //        cout << player[pr][pr_2] << " ";
        //     }
        //     cout << "\n";
        // }
        
        if (escape == false)
            cout << "IMPOSSIBLE\n";
        
        
        

    }
    

}