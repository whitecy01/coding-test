#include <iostream>
#include <queue>       // BFS는 queue 사용
#include <cstring>     // memset
using namespace std;

const int MAX = 50;
int field[MAX][MAX];     // 배추밭
bool visited[MAX][MAX];  // 방문 체크
int M, N, K;              // 가로, 세로, 배추 개수

// 상하좌우 이동
int dx[] = {0, 0, -1, 1}; // x: 열
int dy[] = {-1, 1, 0, 0}; // y: 행

// BFS 탐색
void bfs(int y, int x) {
    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    while (!q.empty()) {
        int curY = q.front().first;
        int curX = q.front().second;
        q.pop();

        // 4방향 탐색
        for (int i = 0; i < 4; i++) {
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
