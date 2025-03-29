#include <iostream>
#include <stack>
#include <queue>

using namespace std;

stack<pair<int,int>> sta;


int main(){
    cin.tie(0);
    ios_base::sync_with_stdio(false);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;

        
            while (!sta.empty())
            {
                auto top = sta.top();
                if (top.first < temp){
                    sta.pop();
                }
                else {
                    cout << top.second << " ";
                    break;
                }
            }
            if (sta.empty()){
                cout << "0 ";
            }
            sta.push({temp, i + 1});
        
    }
    

    
    
}