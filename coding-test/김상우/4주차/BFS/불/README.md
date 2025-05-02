### 문제 이름, 링크
---
- 불
- https://www.acmicpc.net/problem/5427

### 생각한 흐름
- 우선적으로 불의 이동, 그리고 상근이의 이동을 먼저 생각한다.
- 불은 점점 퍼져가기에 fire[][] = true BFS 적용한다.
- 가장 빠른 시간을 적어야 하기에 
- 최대 1000으로 MAX = 1000 잡는다.
- 만약 불이 이미 불이 퍼져있다면 사람은 접근하지 못한다.
- 불을 먼저 큐에 넣고, 다음 사람?
- 모르겠음.


### 틀린 부분
- 우선 BFS를 통해 칸을 확장한다는 개념으로 접근한 부분에서 코드가 어려워짐.
- BFS 하나에서 사람과 불의 이동을 큐 하나로 관리해보려 했지만 코드를 못짜서 문제.

### 코드 첨부 및 설명

- 아래 코드는 두개의 bfs를 활용함.
- 두개의 bfs를 활용하여 해당 칸에 불이나 사람이 도착하는 시간을 저장
- 이후 각 칸을 보면서 불이 도착하는 시간보다 사람이 도착하는 시간이 빠르다면 사람은 해당 칸으로 이동이 가능하다. 라고 가정함.

```cpp 


#include <iostream>
#include <queue>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1000;
int w, h;

char map[MAX][MAX];
int fireTime[MAX][MAX];     // 각 칸에 불이 도착하는 시간
int personTime[MAX][MAX];   // 사람의 이동 시간

int dx[] = {0, 0, -1, 1};   
int dy[] = {-1, 1, 0, 0};   

// 불 bfs
void fireBFS(queue<pair<int, int>> &fireQ) {
    while (!fireQ.empty()) {
        int y = fireQ.front().first;
        int x = fireQ.front().second;
        fireQ.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= h || nx < 0 || nx >= w) continue;
            if (map[ny][nx] == '#' || fireTime[ny][nx] != -1) continue;

            fireTime[ny][nx] = fireTime[y][x] + 1;
            fireQ.push({ny, nx});
        }
    }
}

// 사람 bfs
int personBFS(pair<int, int> start) {
    queue<pair<int, int>> q;
    q.push(start);
    personTime[start.first][start.second] = 0;

    while (!q.empty()) {
        int y = q.front().first;
        int x = q.front().second;
        q.pop();

        for (int i = 0; i < 4; i++) {
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || ny >= h || nx < 0 || nx >= w) {
                return personTime[y][x] + 1;
            }

            if (map[ny][nx] == '#' || personTime[ny][nx] != -1) continue;

            if (fireTime[ny][nx] != -1 && fireTime[ny][nx] <= personTime[y][x] + 1) continue;

            personTime[ny][nx] = personTime[y][x] + 1;
            q.push({ny, nx});
        }
    }

    return -1;
}

int main() {
    int T;
    cin >> T;

    while (T--) {
        cin >> w >> h;
        memset(fireTime, -1, sizeof(fireTime));
        memset(personTime, -1, sizeof(personTime));

        queue<pair<int, int>> fireQ;
        pair<int, int> start;

        // 입력 받기
        for (int i = 0; i < h; i++) {
            string row;
            cin >> row;
            for (int j = 0; j < w; j++) {
                map[i][j] = row[j];
                if (map[i][j] == '*') {
                    fireQ.push({i, j});
                    fireTime[i][j] = 0;
                }
                else if (map[i][j] == '@') {
                    start = {i, j};
                }
            }
        }

        // 불 먼저 퍼트림
        fireBFS(fireQ);

        // 사람 이동 시도
        int result = personBFS(start);
        if (result == -1) cout << "IMPOSSIBLE\n";
        else cout << result << '\n';
    }

    return 0;
}


```

- ...? 너무 어려운디..
