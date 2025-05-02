### 문제 이름, 링크
---
- 유기농 배추
- https://www.acmicpc.net/problem/1012


### 생각한 흐름
- 처음 입력 값 테스트 케이스 수
- 다음 입력값 첫번째가 가로 길이 M 두번째가 세로 길이 N 세번째가 심어져 있는 위치의 개수 K
- 다음 줄부터는 배추의 위치 X : 가로 Y : 세로

- 2차원 배열 활용
- K 줄부터 들어오는 입력값들을 인덱스로 활용하여 다음 인덱스의 값에 + 1해서 배추의 위치를 정한다.
- 이 후 각 인덱스를 돌아다니며 값이 1인곳에 접근 시 해당 값에 +1 이후 상하좌우를 살펴 1이 존재할 경우 해당 인덱스의 값에도 + 1 이후 상하좌우 계속 살피는 방식으로 없을 경우 처음 들어왔던 인덱스에서 다음으로 진행. 반복.

### 틀린 부분
- 일단 내가 생각한 방법은 DFS라고 함.
- 그리고 BFS 코드를 어떻게 짜야할지 아직 모르겠다.

### 코드 첨부 및 설명
```cpp

#include <iostream>
#include <queue>       // BFS는 queue 사용해야한다. 너비 우선 탐색이기 때문에..
#include <cstring>     // memset -> 테스트 케이스가 2개 이상임으로 배열 초기화를 위해 사용한다.
using namespace std; 

const int MAX = 50;  // 최대 50으로 정해져 있기 때문에 배열 크기는 고정해 둔다.
int field[MAX][MAX];     // 배추밭
bool visited[MAX][MAX];  // 방문 체크
int M, N, K;              // 가로, 세로, 배추 개수

// 상하좌우 이동
int dx[] = {0, 0, -1, 1}; // 왼쪽 오른쪽 열 이동.
int dy[] = {-1, 1, 0, 0}; // 위 아래 행 이동. -> 4방향 탐색은 2차원 배열에서 사용하니 설명은 생략.

// BFS 탐색
void bfs(int y, int x) {
    queue<pair<int, int>> q;  //좌표형태로 큐에 저장하기 위해 pair 사용용
    q.push({y, x});           //이 좌표를 큐에 push
    visited[y][x] = true;     //방문 처리까지해준다.

    while (!q.empty()) {                // q가 빌때까지 반복.
        int curY = q.front().first;     // 큐의 첫번째 값을 cury에 두번째 값을 curx에 두고 사용
        int curX = q.front().second;
        q.pop();                        // pop하여 사용한 값 삭제.

        // 4방향 탐색
        for (int i = 0; i < 4; i++) {  //cury 와 curx에 4방향 확인인
            int ny = curY + dy[i];
            int nx = curX + dx[i];

            // 범위 체크
            if (ny >= 0 && ny < N && nx >= 0 && nx < M) {
                // 아직 방문 안 했고 배추가 있으면
                if (!visited[ny][nx] && field[ny][nx] == 1) {
                    visited[ny][nx] = true;
                    q.push({ny, nx}); // 큐에 추가
                }
            }
        }
    }
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> M >> N >> K;

        // 초기화
        memset(field, 0, sizeof(field));
        memset(visited, false, sizeof(visited));

        // 배추 위치 입력
        for (int i = 0; i < K; i++) {
            int x, y;
            cin >> x >> y;
            field[y][x] = 1;
        }

        int wormCount = 0;

        // 모든 칸 순회
        for (int y = 0; y < N; y++) {
            for (int x = 0; x < M; x++) {
                if (!visited[y][x] && field[y][x] == 1) {
                    bfs(y, x); // 새로운 덩어리 탐색
                    wormCount++; // 지렁이 수++
                }
            }
        }

        cout << wormCount << '\n';
    }

    return 0;
}




```

- 어.. 좀 어렵다.