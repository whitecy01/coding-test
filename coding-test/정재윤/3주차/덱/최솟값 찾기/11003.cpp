#include <iostream>
#include <deque>
#include <vector>

using namespace std;

int main(){
    int n, L;
    cin >> n >> L;

    vector<int> vec;
    for (int i = 1; i <= n; i++)
    {
        int temp;
        cin >> temp;
        vec.push_back(temp);
    }

    deque<int> D;
    for (int i = 0; i < n; i++)
    {
        int order = i - L + 1;
        int check = L;
        while (check--)
        {
            if(order >= 0){
                if (!D.empty() && D.front() > vec[i]){
                    D.pop_front();
                    D.push_back(vec[i]);
                }
                else 
                    D.push_back(vec[i]);
            }
            order++;
        }
        cout << D.front() << " ";
        D.pop_front();
        
    }
    

    
    
}