### 문제 이름, 링크
---
- 적록색약
- https://www.acmicpc.net/problem/10026

### 생각한 흐름
- 큐에 담고 빼면서 계산하면 될듯.
- 적록색약일 경우에는 q.front == R && q.front == G 일 경우 bool RG = false 로 상태 관리해서 계산하고
아닐경우에는 RG = true 로 해서 계산시키면 되지 않나?

### 틀린 부분

- visited 초기화할 생각을 못함...

```cpp


for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            if (!visited[y][x]) {
                bfs(y, x, false);
                normalCount++;
            }

// 이 코드 추가. -> visited 초기화 후 적록색약 검사하도록 함.
for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            visited[y][x] = false;


```

### 코드 첨부 및 설명

```cpp

#include <iostream>
#include <queue>
#include <string>
using namespace std;


const int MAX = 100; //최대 100이니 100까지 잡아줌.
char grid[MAX][MAX];
bool visited[MAX][MAX];
int N; // 첫 입력값  넣어줄 N 정의.

    // 알다시피~ 4방향 체크용.
int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};

    //상태관리용 bool 함수 들어가는 값으로는 현재 값 a와 다음 체크할 값 b 그리고 blind 상태 확인용용
bool RG(char a, char b, bool blind){
    if (blind){
        if((a == 'R'||a== 'G')&&(b=='R'||b=='G')) return true; 
        //만약 blind일 경우에 현재 값이 R 또는 G 다음 값이 R 또는 G 일 경우에 두 값은 같다고 정의 해줌.
    }
    //blind가 아니면 그냥 a == b 비교
    return a == b;
}

// 늘 그런 bfs 함수.
void bfs(int x, int y, bool blind) {

    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;

    //현재 값임.
    char color = grid[y][x];

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();
    //다음 값들 체크
        for(int i = 0;i < 4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];

    //늘 그렇듯 범위 체크해주고고
            if(ny < 0 || ny >= N || nx < 0 || nx >= N){
                continue;
            }
    // 방문했었는지 체크.
            if (visited[ny][nx]) {continue;}
    //함수 RG 값에 현재 값 color와 인접값 grid[ny][nx]를 넣어서 색 비교하며 범위 확인.
            if (RG(color, grid[ny][nx], blind)) {
                visited[ny][nx] = true;
                q.push({ny, nx});

        }

    } 

    }

}

int main() {
    cin >> N;
    for (int i = 0; i < N; i++) {
        string line;
        cin >> line;
        for (int j = 0; j < N; j++) {
            grid[i][j] = line[j];
        }
    }

    int normalC = 0;
    int blindC = 0;
     //일단 일반인 blind = false로
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            if (!visited[y][x]) {
                bfs(y, x, false);
                normalC++;
            }

        //visited 함수 초기화 해야함...
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            visited[y][x] = false;

            // 적록색약이니 true
    for (int y = 0; y < N; y++)
        for (int x = 0; x < N; x++)
            if (!visited[y][x]) {
                bfs(y, x, true);
                blindC++;
            }

    cout << normalC << ' ' << blindC << '\n';
    return 0;
}


```