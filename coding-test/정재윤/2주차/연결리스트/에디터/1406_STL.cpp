#include <iostream>
#include <list>
#include <iterator>

using namespace std;

list<char> ls;

int main(){
    string str;
    cin >> str;
    for (int i = 0; i < str.size(); i++)
    {
        ls.push_back(str[i]);
    }
    list<char>::iterator it = ls.end();

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        char temp;
        cin >> temp;
        if (temp == 'L'){
            if (ls.begin() != it){
                // cout << "here\n";
                it--;
            }
            // cout << *it << "\n";
        }
        else if (temp == 'D'){
            if (ls.end() != it){
                it++;
            }
        }
        else if (temp == 'B'){
            if (it != ls.begin()){
                --it;
                it = ls.erase(it);
                // cout << "it : " << *it << "\n";
            }
                
                // cout << *it << "\n";
        }
        else if (temp == 'P'){
            char en;
            cin >> en;
            ls.insert(it, en);
            // cout << "it : " << *it << "\n";
        }

        // cout << "\n";
    }

    for (list<char>::iterator iter = ls.begin(); iter != ls.end(); iter++)
    {
        cout << *iter;
    }
    
}