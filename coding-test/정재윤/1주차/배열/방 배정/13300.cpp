#include <iostream>
#include <algorithm>
using namespace std;

int arr[2][8];

int main(){
    int n, k;
    cin >> n >> k;

    for (int i = 0; i < n; i++)
    {
        int one, second;
        cin >> one >> second;
        arr[one][second]++;
    }
    int ans = 0;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 8; j++)
        {
            // cout << "check : " << arr[i][j] << "\n";
            ans += arr[i][j] / k;  // 이 부분 헷갈려야함
            if (arr[i][j] % k) ans++;
            // arr[i][j] = temp;
            // cout << "ans : " << ans << "\n";
            
        }
        // cout << "\n";
    }
    cout << ans << "\n";
}