### 문제이름, 링크
---
- 벽 부수고 이동하기
- https://www.acmicpc.net/problem/2206

### 생각한 흐름
- tuple을 활용해서 세 번째 칸에 벽을 부쉈나 안 부쉈나를 확인해서 부순 것대로 부수지 않은 것끼리 각각 queue에 넣어서 진행하면 될 것 같음
- 밑 코드까지는 작성했는데 뭔가 안 될 것 같음 
```cpp
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
string board[1002];
int view[1002][1002];

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);
    int n;
    cin >> n;

    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++)
    {
        cin >> board[i];
    }
    for (int i = 0; i < h; i++)
    {
        fill(view[i], view[i] + w, -1);
    }
    queue<tuple<int,int,bool>> Q;
    view[0][0];
    Q.push({0,0,false});
    while (!Q.empty())
    {
        auto cur = Q.front(); Q.pop();
        for (int idx = 0; idx < 4; idx++)
        {
            int nx = get<0>(cur) + dx[idx];
            int ny = get<1>(cur) + dy[idx];
            if (nx < 0 || nx >= h || ny < 0 || nx >= w) continue;
            if (board[nx][ny] == '1' || view[nx][ny] >= 0) continue;
            Q.push({nx,ny,true});
            view[nx][ny] = view[get<0>(cur)][get<1>(cur)] + 1;
        }

        
        if (get<2>(cur) == true){

        }
        else if (){

        }

        
        
    }
    


    

}
```
- 이건 도저히 안 풀려서 도움을 받음 
- tuple을 사용해서 마지막에 부수고 가는 것이지 아닌지 판단
- 방문 표시를 벽을 부순 것과 부수지 않은 것으로 나누어서 진행
- 중요한 부분
    - 길(0)이라면, 벽을 부쉈든 안 부쉈든 지금 상태 그대로 이동
    - 벽(1)이라면, 벽을 아직 안 부쉈을 때만 부수고 간다고 표시하고 이동 
- 하다가 3차원 배열이 헷갈림
[6][4][2] :
→ 6×4짜리 큰 바둑판이 하나 있는데,
각 칸에 메모장이 2개 붙어 있음 (상태별 메모).

[2][6][4] :
→ 6×4짜리 바둑판이 아예 2개가 따로 있음. (0번 맵, 1번 맵)

첫 번재 테스트 케이스
```plaintext
6 4
0100
1110
1000
0000
0111
0000
--------------
1 -1 -1 -1 
-1 -1 -1 -1 
-1 -1 -1 -1 
-1 -1 -1 -1 
-1 -1 -1 -1 
-1 -1 -1 -1 
--------------
1 2 3 4 
2 -1 -1 5 
-1 8 7 6 
10 9 8 7 
11 -1 -1 -1 
12 13 14 15 
15
```

### 코드첨부와 코드 설명
```cpp
#include <iostream>
#include <queue>
#include <tuple>
using namespace std;

//한글 순서
//1. dist를 2개로 만들어서 벽을 안 깨고 다니는 것과 벽을 꺠고 다니는 것 체크할 수 있는 방법 
//2. 벽을 깨지 않든, 벽을 깨든 0이면 전부 다 갈 수 있어야 하고 한 번이라도 꺴으면 깨면 안 됨
int dx[4] = {1, -1, 0, 0};
int dy[4] = {0, 0, 1, -1};
char board[1002][1002];
int view[1002][1002][2];
// view[x][y][0] : 벽을 부수지 않고 (x,y)까지 도착했을 때 거리
// view[x][y][1] : 벽을 한 번 부수고 (x,y)까지 도착했을 때 거리

int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int h, w;
    cin >> h >> w;
    for (int i = 0; i < h; i++)
        for (int j = 0; j < w; j++)
            cin >> board[i][j];
    memset(view, -1, sizeof(view));
    view[0][0][0] = view[0][0][1] = 1;
    queue<tuple<int,int,int>> Q;
    Q.push({0,0,0});
    while (!Q.empty())
    {
        int cur_x,cur_y,broken;
        tie(cur_x,cur_y,broken) = Q.front(); Q.pop();
        if (cur_x == h - 1 && cur_y == w - 1) {
            cout << view[cur_x][cur_y][broken] << "\n";
            return 0;
        }
        for (int idx = 0; idx < 4; idx++)
        {
            int nx = cur_x + dx[idx];
            int ny = cur_y + dy[idx];
            if (nx < 0 || nx >= h || ny < 0 || ny >= w) continue;
            if (board[nx][ny] == '0' && view[nx][ny][broken] == -1){ // 길(0)이라면, 벽을 부쉈든 안 부쉈든 지금 상태 그대로 이동
                view[nx][ny][broken] = view[cur_x][cur_y][broken] + 1;
                Q.push({nx,ny,broken});
            }
            if (!broken && board[nx][ny] == '1' && view[nx][ny][1] == -1 ){ //벽(1)이라면, 벽을 아직 안 부쉈을 때만 부수고 간다고 표시하고 이동 
                view[nx][ny][1] = view[cur_x][cur_y][broken] + 1;
                Q.push({nx, ny, 1});
             }
        }
    }
    cout << "--------------\n";
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cout << view[i][j][0] << " ";
        cout << "\n";
    }
    cout << "--------------\n";
    
    for (int i = 0; i < h; i++) {
        for (int j = 0; j < w; j++)
            cout << view[i][j][1] << " ";
        cout << "\n";
    }
    cout << "-1\n";
}
```


