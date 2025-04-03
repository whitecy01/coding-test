#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

int main(){
    deque<int> D;

    int n,m;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        D.push_back(i);
    }

    int ans = 0;
    for (int i = 0; i < m; i++)
    {
        int num_find;
        cin >> num_find;
        int idx = find(D.begin(),D.end(), num_find) - D.begin(); //find 까먹음
        
        // cout << "idx : " << idx << " num_find : " << num_find << "\n";
        int left, right;
        left = idx;
        right = D.size() - idx;
        if (left < right){
            ans += left;
            while (left--)
            {
                D.push_back(D.front());
                D.pop_front();
                
            }
            
        }
        else {
            ans += right;
            while (right--)
            {
                D.push_front(D.back());
                D.pop_back();
            }
        }
        D.pop_front();
        // cout << "ans : " << ans << "\n";
    }
    cout << ans << "\n";
    
}