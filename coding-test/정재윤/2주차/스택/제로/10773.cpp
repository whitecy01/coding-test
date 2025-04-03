#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;

    int ans = 0;
    stack<int> sta;
    for (int i = 0; i < n; i++)
    {
        int num;
        cin >> num;

        if (num == 0){
            if (!sta.empty())
                sta.pop();
        }
        else
            sta.push(num);
    }
    int size_sta = sta.size();
    for (int i = 0; i < size_sta; i++)
    {
        ans += sta.top();
        sta.pop();
    }
    cout << ans << "\n";
    
    
}