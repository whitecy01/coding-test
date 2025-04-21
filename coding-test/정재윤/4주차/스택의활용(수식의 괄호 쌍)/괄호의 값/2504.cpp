#include <iostream>
#include <stack>

using namespace std;

stack<char> sta;

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;
    cin >> str;
    int sum = 0;
    int num = 1;
    for (int i = 0; i < str.size(); i++)
    {
        if (str[i] == '('){
            num *= 2;
            sta.push(str[i]);
        }
        else if (str[i] == '['){
            num *= 3;
            sta.push(str[i]);
        }
        else {
            if (str[i] == ')'){
                if (sta.empty() || sta.top() != '('){
                    cout << 0;
                    return 0;
                }
                if (str[i - 1] == '(') sum += num;
                sta.pop();
                num /= 2;
            }
            else{
                if (str[i] == ']'){
                    if (sta.empty() || sta.top() != '['){
                        cout << 0;
                        return 0;
                    }
                    if (str[i - 1] == '[') sum += num;
                    sta.pop();
                    num /= 3;
                }
            }
        }

    }
    cout << sum << "\n";

    
}