#include <iostream>
#include <queue>

using namespace std;

int dx[8] = {-2,-2,2,2,-1,-1,1,1};
int dy[8] = {-1,1,-1,1,-2,2,-2,2};


int main(){
    cin.tie(0);
    ios::sync_with_stdio(0);

    int n;
    cin >> n; // 테스트 케이스 수
    for (int i = 0; i < n; i++)
    {
        int size; // 체스 크기
        cin >> size;
        int board[302][302];
        int view[302][302];
        queue<pair<int,int>> Q;
        for (int j = 0; j < size; j++)
        {
            fill(board[j],board[j] + size, 0);
            fill(view[j],view[j] + size, -1);
        }
        int start_x, start_y; // 나이트 시작 위치
        cin >> start_x >> start_y;
        Q.push({start_x, start_y});
        view[start_x][start_y] = 1;
        int end_x, end_y; // 끝나는 지점
        cin >> end_x >> end_y;
        bool check = false;
        if (start_x == end_x && start_y == end_y){
            cout << "0\n";
            continue;
        }
        while (!Q.empty())
        {
            auto cur = Q.front(); Q.pop();
            for (int idx = 0; idx < 8; idx++)
            {
                int nx = cur.first + dx[idx];
                int ny = cur.second + dy[idx];
                if (nx == end_x && ny == end_y){
                    cout << view[cur.first][cur.second]  << "\n";
                    check = true;
                    break;
                }
                if (nx < 0 || nx >= size || ny < 0 || ny >= size) continue;
                if (view[nx][ny] >= 0) continue;
                view[nx][ny] = view[cur.first][cur.second] + 1;
                Q.push({nx,ny});
            }
            if (check == true){
                // for (int q = 0; q < size; q++)
                // {
                //     for (int w = 0; w < size; w++)
                //     {
                //         cout << view[q][w] << " ";
                //     }
                //     cout << "\n";
                // }
                break;
            }
        }    
    }

}