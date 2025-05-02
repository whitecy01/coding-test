### 문제이름, 링크
- 유기농 배추
- https://www.acmicpc.net/problem/1012

### 생각한 흐름
- 이건 수업에서 한 BFS랑 똑같이 풀면 된다. 
- 단지 테스트 케이스가 여러개 있으니 초기화 부분을 조심

### 코드첨부와 코드 설명
```cpp
#include <iostream>
#include <queue>

using namespace std;

int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int T;
    cin >> T;
    for (int i = 0; i < T; i++)
    {
        int m, n, k;
        cin >> m >> n >> k; // m이 가로, n이 세로
        int board[52][52];
        for (int q = 0; q < 52; q++){ fill(board[q], board[q] + m, 0);}
        int view[52][52];
        for (int q = 0; q < 52; q++){ fill(view[q], view[q] + m, 0);}
        
        for (int in = 0; in < k; in++)
        {
            int x,y;
            cin >> x >> y;
            board[y][x] = 1;
        }
        int count = 0;
        for (int o = 0; o < n; o++)
        {
            for (int p = 0; p < m; p++)
            {
                if (board[o][p] == 1 && view[o][p] == 0){
                    queue<pair<int,int>> Q;
                    count++;
                    Q.push({o,p});
                    view[o][p] = 1;
                    while (!Q.empty())
                    {
                        auto cur = Q.front(); Q.pop();
                        for (int idx = 0; idx < 4; idx++)
                        {
                            int nx = cur.first + dx[idx];
                            int ny = cur.second + dy[idx];
                            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if (board[nx][ny] == 0 || view[nx][ny] == 1) continue;
                            Q.push({nx,ny});
                            view[nx][ny] = 1;
                        }
                    }
                }
            }
        }
        cout << count << "\n";
    }
}
```


