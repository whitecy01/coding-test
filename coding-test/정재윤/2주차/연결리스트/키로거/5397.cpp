#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        list<char> ls;
        list<char>::iterator iter = ls.begin();
        for (int j = 0; j < str.size(); j++)
        {
            if (str[j] == '<'){
                if (iter != ls.begin()){
                    iter--;
                }
            }
            else if (str[j] == '>'){
                if (iter != ls.end()){
                    iter++;
                }
            }
            else if (str[j] == '-'){
                if (iter != ls.begin()){
                    iter--;
                    iter = ls.erase(iter);
                }
            }
            else {
                ls.insert(iter, str[j]);
            }
        }
        for (auto c : ls)
        {
            cout << c;
        }
        cout <<"\n";
    }
    
}