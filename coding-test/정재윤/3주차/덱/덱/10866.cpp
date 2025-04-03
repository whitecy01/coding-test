#include <iostream>
#include <deque>

using namespace std;

int main(){
    int n;

    cin >> n;
    string str;
    deque<int> de;
    for (int i = 0; i < n; i++)
    {
        cin >> str;
        if (str == "push_front")
        {
            int num;
            cin >> num;
            de.push_front(num);
        }
        else if (str == "push_back"){
            int num;
            cin >> num;
            de.push_back(num);
        }
        else if (str == "pop_front"){
            if (!de.empty()) 
            {
                cout << de.front() << "\n";
                de.pop_front();
            }
            else 
                cout << "-1\n";
        }
        else if (str == "pop_back"){
            if (!de.empty()) 
            {
                cout << de.back() << "\n";
                de.pop_back();
            }
            else 
                cout << "-1\n";
        }
        else if (str == "size") { cout << de.size() << "\n";}
        else if (str == "empty") { cout << de.empty() << "\n";}
        else if (str == "front") { 
            if (!de.empty()) 
            {
                cout << de.front() << "\n";
            }
            else 
                cout << "-1\n";
        }
        else if (str == "back"){
            if (!de.empty()) 
                cout << de.back() << "\n";
            else 
                cout << "-1\n";
        }
        
    }
    
}