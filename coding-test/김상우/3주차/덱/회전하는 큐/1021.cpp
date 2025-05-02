#include <iostream>     
#include <deque>        
using namespace std;

int main() {
    int n, m;
    cin >> n >> m; 

    deque<int> dq;
    for (int i = 1; i <= n; i++) {
        dq.push_back(i); 
    }

    int total_ops = 0;  // 총 연산 횟수

    while (m--) { 
        int target;
        cin >> target;  // 이번에 뽑아야 할 숫자

        int idx = 0;
        // 덱 안에서 target이 몇 번째 위치에 있는지 찾기
        for (int i = 0; i < dq.size(); i++) {
            if (dq[i] == target) {
                idx = i;  // 찾은 위치 저장
                break;
            }
        }

        // 덱의 앞쪽 절반에 위치한다면 → 왼쪽으로 회전
        if (idx <= dq.size() / 2) {
            // 덱의 맨 앞이 target이 될 때까지 왼쪽 회전
            while (dq.front() != target) {
                dq.push_back(dq.front());  // 맨 앞 값을 맨 뒤로 보냄
                dq.pop_front();            // 맨 앞 제거
                total_ops++;               // 연산 횟수 증가
            }
        } 
        // 덱의 뒷쪽 절반에 위치한다면 → 오른쪽으로 회전
        else {
            while (dq.front() != target) {
                dq.push_front(dq.back());  // 맨 뒤 값을 맨 앞에 삽입
                dq.pop_back();             // 맨 뒤 제거
                total_ops++;               // 연산 횟수 증가
            }
        }

        // 맨 앞이 target이므로 제거 (이건 연산 횟수에 포함 X)
        dq.pop_front();
    }

    // 총 회전 연산 횟수 출력
    cout << total_ops << endl;
    return 0;
}