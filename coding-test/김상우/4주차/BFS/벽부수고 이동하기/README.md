### 문제 이름, 링크
---
- 벽 부수고 이동하기
- https://www.acmicpc.net/problem/2206

### 생각한 흐름
- 일단 상태관리를 사용한다.
- 벽을 부수기 전이라면 bool can = true 하나를 부셨다면 false로 정의한다.
- 각 이동하는 배열에 시간을 저장한다. time[][] = time[ny][nx] + 1
- 조건문을 정의한다. 만약 이동하지 못한다면과 N과 M을 벗어나지 못하도록
- 하여 배열안에 0이 존재한다면 이동하지 못하였다고 판단 -1을 출력한다.

### 틀린 부분
- ? 뭐 어떻게 풀지..?


### 코드 첨부 및 설명
```cpp
#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

const int MAX = 1000;
int N, M;
char grid[MAX][MAX];
bool visited[MAX][MAX][2];  // [y][x][0:안부숨, 1:부숨]

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

struct State {
    int y, x;
    int dist;        // 현재까지의 거리
    bool broken;     // 벽 부쉈는지 여부
};

int bfs() {
    queue<State> q;
    q.push({0, 0, 1, false});
    visited[0][0][0] = true;

    while (!q.empty()) {
        State cur = q.front(); q.pop();

        // 도착!
        if (cur.y == N - 1 && cur.x == M - 1)
            return cur.dist;

        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            int nextBreak = cur.broken ? 1 : 0;

            // 범위 벗어나면 스킵
            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

            // 다음 칸이 벽이 아님
            if (grid[ny][nx] == '0' && !visited[ny][nx][nextBreak]) {
                visited[ny][nx][nextBreak] = true;
                q.push({ny, nx, cur.dist + 1, cur.broken});
            }

            // 다음 칸이 벽이고, 아직 안 부쉈다면
            if (grid[ny][nx] == '1' && !cur.broken && !visited[ny][nx][1]) {
                visited[ny][nx][1] = true;
                q.push({ny, nx, cur.dist + 1, true});
            }
        }
    }

    return -1; // 도달 불가
}

int main() {
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        string row; cin >> row;
        for (int j = 0; j < M; j++)
            grid[i][j] = row[j];
    }

    cout << bfs() << '\n';
    return 0;
}



```