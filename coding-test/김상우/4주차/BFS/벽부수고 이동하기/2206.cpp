#include <iostream>
#include <queue>
#include <string>
#include <tuple>
using namespace std;

const int MAX = 1000;
int N, M;
char grid[MAX][MAX];
bool visited[MAX][MAX][2];

int dy[] = {-1, 1, 0, 0};
int dx[] = {0, 0, -1, 1};

struct State {
    int y, x;
    int dist;       
    bool broken;     
};

int bfs() {
    queue<State> q;
    q.push({0, 0, 1, false});
    visited[0][0][0] = true;

    while (!q.empty()) {
        State cur = q.front(); q.pop();

       
        if (cur.y == N - 1 && cur.x == M - 1)
            return cur.dist;

        for (int dir = 0; dir < 4; dir++) {
            int ny = cur.y + dy[dir];
            int nx = cur.x + dx[dir];
            int nextBreak = cur.broken ? 1 : 0;

            if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;

            if (grid[ny][nx] == '0' && !visited[ny][nx][nextBreak]) {
                visited[ny][nx][nextBreak] = true;
                q.push({ny, nx, cur.dist + 1, cur.broken});
            }

            if (grid[ny][nx] == '1' && !cur.broken && !visited[ny][nx][1]) {
                visited[ny][nx][1] = true;
                q.push({ny, nx, cur.dist + 1, true});
            }
        }
    }

    return -1;
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
