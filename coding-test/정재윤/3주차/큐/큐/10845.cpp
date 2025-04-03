#include <iostream>
#include <queue>

using namespace std;

int main(){
    int n;
    cin >> n;

    queue<int> Q;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        if (str == "push"){
            int temp;
            cin >> temp;
            Q.push(temp);
        }
        else if (str == "front"){
            if (!Q.empty())
                cout << Q.front() << "\n";
            else 
                cout << "-1\n";
        }
        else if (str == "back"){
            if (!Q.empty())
                cout << Q.back() << "\n";
            else 
                cout << "-1\n";
        }
        else if (str == "pop"){
            if (!Q.empty()){
                cout << Q.front() << "\n";
                Q.pop();
            }
            else 
                cout << "-1\n";
        }
        else if (str == "size"){
            cout << Q.size() << "\n";
        }
        else if (str == "empty"){
            if (!Q.empty()){
                cout << "0" << "\n";
            }
            else 
                cout << "1\n";
        }
    }
    
    
}