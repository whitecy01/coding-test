#include <iostream>
#include <stack>
#include <queue>

using namespace std;

stack<int> sta;
queue<int> Q;
queue<char> ans;


int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        int temp; cin >> temp;
        Q.push(temp);
    }
    
    int l = 1;
    while (!Q.empty())
    {
        if (sta.size() && sta.top() == Q.front()){
                sta.pop();
                Q.pop();
                ans.push('-');
        }
        else if (l <= Q.front()){
            while (l <= Q.front())
            {
                sta.push(l++);
                ans.push('+');
            }
        }
        else {
            cout << "NO\n";
            return 0;
        }
    }
    while (ans.size())
    {
        cout << ans.front() << "\n";
        ans.pop();

    }
    

    
    
}