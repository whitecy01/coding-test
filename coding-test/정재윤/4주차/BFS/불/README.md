### 문제이름, 링크
---
- 불
- https://www.acmicpc.net/problem/5427

### 생각한 흐름
- fire는 여러 개의 시작점을 가질 수 있으니 거기에 맞게 BFS를 돌려서 최단 거리를 구한다.
- player는 BFS를 돌리는데 불에 접근해서는 안 되며 불의 최단 거리 값에서 자신이 가는 거리 값보다 높아야한다. 즉 같거나 낮으면 탈출 할 수 없다, 또한 밖에 탈출하는 경우는 탈출하는 것으로 간주된다.

- 여기까지 풀었는데 계속 틀렸다고 한다 도대체 뭐가 틀린 걸까
```cpp
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
                if (board[nx][ny] == '#' || board[nx][ny] == '*' || player[nx][ny] >= 0 || fire[nx][ny] <= player[cur.first][cur.second] + 1) continue;
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
```

- 찾아보니  (fire[nx][ny] >= 0 && fire[nx][ny] <= player[cur.first][cur.second] + 1) 이놈이 문제였다
    - 이게 fire[nx][ny] >= 0 이게 없으면 player가 불이 없는 지점 즉, -1 부분으로 가지를 못한다 예를 들어 -1 <= player+1은 항상 참이기 때문에 갈 수 있어야하는데 그냥 continue를 해버리는 것이다.



### 코드첨부와 코드 설명
```cpp
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
```


