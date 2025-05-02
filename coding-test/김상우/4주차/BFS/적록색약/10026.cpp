#include <iostream>
#include <queue>
#include <string>
using namespace std;

const int MAX = 100;
char grid[MAX][MAX];
bool visited[MAX][MAX];
int N;


int dy[] = {-1,1,0,0};
int dx[] = {0,0,-1,1};


bool RG(char a, char b, bool blind){
    if (blind){
        if((a == 'R'||a== 'G')&&(b=='R'||b=='G')) return true;
    }
    return a == b;
}


void bfs(int x, int y, bool blind) {

    queue<pair<int, int>> q;
    q.push({y, x});
    visited[y][x] = true;


    char color = grid[y][x];

    while(!q.empty()){
        int cy = q.front().first;
        int cx = q.front().second;
        q.pop();

        for(int i = 0;i < 4; i++){
            int ny = cy + dy[i];
            int nx = cx + dx[i];


            if(ny < 0 || ny >= N || nx < 0 || nx >= N){
                continue;
            }

            if (visited[ny][nx]) {continue;}

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
