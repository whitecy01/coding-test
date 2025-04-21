#include <iostream>
#include <stack>

using namespace std;

stack<char> sta;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    int ans = 0;
    for (int i = 0; i < str.size(); i++)
    {
        char first = str[i];
        char second = str[i + 1]; 
        // cout << "i : " << i << "  first : " << first << " second : " << second <<"\n";
        if (first ==  '(' && second == ')'){
            ans += sta.size();
            // cout << "1. i : " << i << "  ans : " << ans <<"\n";
            // if (i < str.size()- 1)
            i++;
        }
        else if (!sta.empty() && sta.top() == '(' && first == ')'){
            // cout << "2. i : " << i << "  ans : " << ans << " sta.size() : " << sta.size() << "\n";
            ans++;
            sta.pop();
        }else{
            sta.push(first);
            // cout << "3. i : " << i << "  ans : " << ans <<"\n";
        }
    }
    cout << ans << "\n";
    
}