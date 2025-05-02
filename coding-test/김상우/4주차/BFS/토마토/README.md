### 문제 이름, 링크
---
- 토마토
- https://www.acmicpc.net/problem/7569


### 생각한 흐름
- 6개 방향은 어떻게 정의하나요...?
- 이 문제를 어떻게 풀죠...?


### 틀린 부분
- 다른 사람의 코드를 봐도 모르겠네요.
- 진짜 미치겠습니다.


### 코드 첨부 및 설명
```cpp


#include <iostream>
#include <queue>
using namespace std;

const int MAX = 100;
int M, N, H;
int box[MAX][MAX][MAX];         // [층][행][열]
int days[MAX][MAX][MAX];        // 날짜 저장
bool visited[MAX][MAX][MAX];    // 방문 여부용용

// 6방향: 위, 아래, 앞, 뒤, 왼쪽, 오른쪽
int dz[] = {-1, 1, 0, 0, 0, 0}; //일단 3차원...이면 좌표값을 3개를 쓸 뿐인가?
int dy[] = {0, 0, -1, 1, 0, 0};
int dx[] = {0, 0, 0, 0, -1, 1};

queue<tuple<int, int, int>> q;  //tuple..?뭐여 이건..

void bfs() {
    while (!q.empty()) {
        // 이게 현재 위치인듯.
        auto [z, y, x] = q.front(); q.pop();

        //이후 6방향 탐색색
        for (int i = 0; i < 6; i++) {
            int nz = z + dz[i];
            int ny = y + dy[i];
            int nx = x + dx[i];

            // 범위 체크
            if (nz < 0 || nz >= H || ny < 0 || ny >= N || nx < 0 || nx >= M)
                continue;

            // 안 익은 토마토만 익힘
            if (!visited[nz][ny][nx] && box[nz][ny][nx] == 0) {
                visited[nz][ny][nx] = true; //방문표시
                box[nz][ny][nx] = 1;    //익음 표시시
                days[nz][ny][nx] = days[z][y][x] + 1; //현재 칸 = 이전 +1일해주고고
                q.push({nz, ny, nx});       //큐에 다음 칸 저장해줌.
            }
        }
    }
}

int main() {
    cin >> M >> N >> H;
        //전체 박스를 입력해주고 
    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                cin >> box[z][y][x];
                if (box[z][y][x] == 1) {
                    //익은 토마토는 미리 처리해 두는건가? 
                    q.push({z, y, x}); // 시작점 여러 개
                    visited[z][y][x] = true;
                }
            }
        }
    }
    //bfs 실행
    bfs();
    //모든 칸 검사 ㄱㄱㄱ
    int maxDay = 0;
    for (int z = 0; z < H; z++) {
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (box[z][y][x] == 0) {
                    cout << -1 << '\n';
                    return 0; // 안 익은 토마토 있음
                }
                //maxDay......?????
                maxDay = max(maxDay, days[z][y][x]);
            }
        }
    }

    cout << maxDay << '\n';
    return 0;
}





```