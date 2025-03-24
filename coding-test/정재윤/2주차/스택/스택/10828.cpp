#include <iostream>
#include <stack>

using namespace std;

int main(){
    int n;
    cin >> n;
    stack<int> sta;
    for (int i = 0; i < n; i++)
    {
        string temp;
        cin >> temp;
        if (temp == "push"){
            int te;
            cin >> te;
            sta.push(te);
        }
        else if (temp == "top"){
            if (sta.empty()){
                cout << "-1\n";
            }
            else {
                cout << sta.top() << "\n";
            }
        }
        else if (temp == "pop"){
            if (sta.empty()){
                cout << "-1\n";
            }
            else {
                cout << sta.top() << "\n";
                sta.pop();
            }
        }
        else if (temp == "size"){
            cout << sta.size() << "\n";
        }
        else if (temp == "empty"){
            if (sta.empty()){
                cout << "1\n";
            }
            else 
                cout << "0\n";
        }
    }
    
}