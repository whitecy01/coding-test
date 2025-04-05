#include <stack>
#include <iostream>

using namespace std;

int main(){
    while (1)
    {
        string str;
        getline(cin, str);
        if (str == ".")
            break;
        stack<char> sta;
        bool check = true;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == '(' || str[i] == '['){
                sta.push(str[i]);
            }
            else if (str[i] == ')' ){
                if (sta.empty() || sta.top() != '('){
                    cout << "no\n";
                    check =false;
                    break;
                }
                else 
                    sta.pop();
            }
            else if (str[i] == ']'){
                if (sta.empty() || sta.top() != '['){
                    cout << "no\n";
                    check = false;
                    break;
                }
                else 
                    sta.pop();
            }
        }
        if (check == false)
            continue;

        if (!sta.empty() ){
            cout << "no\n";
        }
        else 
            cout << "yes\n";
    }
}