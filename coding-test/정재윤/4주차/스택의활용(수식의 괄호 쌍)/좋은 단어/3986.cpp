#include <iostream>
#include <stack>

using namespace std;

string str[1000002];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        string str_temp;
        cin >> str_temp;
        str[i] = str_temp;
    }

    long long count = 0;
    for (int i = 0; i < n; i++)
    {    
        stack<char> sta;
        long long temp_count = 0;
        string str_str = str[i];
        for (int j = 0; j < str_str.size(); j++)
        {
            if (!sta.empty() && str_str[j] == sta.top()){
                sta.pop();
                
            }
            else{
                sta.push(str_str[j]);
            }
        }
        
        if (sta.empty())
            count++;
    }
    cout << count << "\n";
}