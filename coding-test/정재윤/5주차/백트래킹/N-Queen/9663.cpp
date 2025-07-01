// #include <bits/stdc++.h>
// using namespace std;

// bool isused1[40];
// bool isused2[40];
// bool isused3[40];
// int col[40];      // 각 행에 선택한 열

// int n;
// int cnt = 0;

// void print_state(const string& label, int depth) {
//     cout << string(depth*2, ' ') << label << " 상태:\n";
//     cout << string(depth*2, ' ') << "isused1: ";
//     for (int i = 0; i < n; i++) cout << isused1[i] << " ";
//     cout << "\n";
//     cout << string(depth*2, ' ') << "isused2: ";
//     for (int i = 0; i < 2*n; i++) cout << isused2[i] << " ";
//     cout << "\n";
//     cout << string(depth*2, ' ') << "isused3: ";
//     for (int i = 0; i < 2*n; i++) cout << isused3[i] << " ";
//     cout << "\n";
// }

// void print_board(int depth) {
//     cout << string(depth*2, ' ') << "현재 체스판:\n";
//     for (int r = 0; r < depth; r++) {
//         cout << string(depth*2, ' ');
//         for (int c = 0; c < n; c++) {
//             if (c == col[r]) cout << "Q ";
//             else cout << ". ";
//         }
//         cout << "\n";
//     }
// }

// void func(int cur) {
//     cout << ">> func(" << cur << ") 진입\n";

//     if (cur == n) {
//         cnt++;
//         cout << "!! 해 발견, cnt=" << cnt << "\n";
//         print_state("해 상태", cur);
//         print_board(cur);
//         return;
//     }

//     for (int i = 0; i < n; i++) {
//         if (isused1[i] || isused2[i+cur] || isused3[i-cur+n-1])
//             continue;

//         cout << "선택: row=" << cur << ", col=" << i << "\n";
//         isused1[i] = 1;
//         isused2[i+cur] = 1;
//         isused3[i-cur+n-1] = 1;
//         col[cur] = i;                      // 선택 열 기록

//         print_state("마킹 후", cur);
//         print_board(cur + 1);              // 현재까지의 체스판

//         func(cur + 1);

//         cout << "해제: row=" << cur << ", col=" << i << "\n";
//         isused1[i] = 0;
//         isused2[i+cur] = 0;
//         isused3[i-cur+n-1] = 0;

//         print_state("해제 후", cur);
//     }

//     cout << "<< func(" << cur << ") 종료\n";
// }

// int main() {
//     ios::sync_with_stdio(0);
//     cin.tie(0);
//     cin >> n;
//     func(0);
//     cout << "총 해의 개수: " << cnt << endl;
// }



#include <iostream>

using namespace std;


bool isused1[40];
bool isused2[40];
bool isused3[40];
int n;
int cnt;

void func(int cur){
    if (cur == n){
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++)
    {
        if (isused1[i] || isused2[i + cur] || isused3[i - cur + n - 1])
            continue;
        isused1[i] = 1;
        isused2[i + cur] = 1;
        isused3[i - cur + n - 1] = 1;
        func(cur + 1);
        isused1[i] = 0;
        isused2[i + cur] = 0;
        isused3[i - cur + n - 1] = 0;
    }
    

}


int main(){
    cin >> n;
    func(0);
    cout << cnt;
}