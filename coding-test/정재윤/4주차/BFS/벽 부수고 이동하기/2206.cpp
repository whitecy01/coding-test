#include <iostream>
#include <queue>
#include <tuple>
#include <cstring>
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
            // cout << "--------------\n";
            // for (int i = 0; i < h; i++) {
            //     for (int j = 0; j < w; j++)
            //         cout << view[i][j][0] << " ";
            //     cout << "\n";
            // }
            // cout << "--------------\n";
            
            // for (int i = 0; i < h; i++) {
            //     for (int j = 0; j < w; j++)
            //         cout << view[i][j][1] << " ";
            //     cout << "\n";
            // }
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

    cout << "-1\n";
}