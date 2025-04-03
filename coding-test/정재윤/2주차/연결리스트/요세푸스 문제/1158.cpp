#include <iostream>
#include <list>
#include <queue>


using namespace std;


int main(){

    int n,k;
    cin >> n >> k;

    queue<int> ls;
    vector<int> ans;
    for (int i = 1; i <= n; i++)
    {
        ls.push(i);        
    }

    cout << "<";
    while (!ls.empty())
    {
        for (int j = 0; j < k - 1; j++)
        {
            ls.push(ls.front());
            ls.pop();
        }
        ans.push_back(ls.front());
        ls.pop();
    }
    
    for (int i = 0; i < ans.size(); i++)
    {
        cout << ans[i];
        if (i != ans.size() - 1)
            cout << ", ";
    }
    cout << ">\n";
    
    
}


// int main(){

//     int n,k;
//     cin >> n >> k;

//     list<int> ls;
//     vector<int> ans;
//     for (int i = 1; i <= n; i++)
//     {
//         ls.push_back(i);        
//     }
    
//     list<int>::iterator iter = ls.begin();

    
//     for (int i = 0; i < n; i++)
//     {
//         int k_temp = k - 1;

//         for (int i = 0; i < k_temp; i++)
//         {
//             if (iter == ls.end()){
//                 iter = ls.begin();
//             }
//             iter++;
//         }
        
//         ans.push_back(*iter);
        
//         iter = ls.erase(iter);
//         if (iter == ls.end())
//             iter = ls.begin();
//         for (auto a : ans)
//         {
//             cout << a << " ";
//         }
//         cout << "\n";
//     }
//     for (auto a : ans)
//     {
//         cout << a << " ";
//     }
    
    
    
// }

// 1 2 3 4 5 6 7 
// 1 2 4 5 6 7 // 3
// 1 2 4 5 7 // 3 6
// 1 4 5 7 // 3 6 2
// 1 4 5 // 3 6 2 7
// 1 4 // 3 6 2 7 5
// 4 // 3 6 2 7 5 1
//3 6 2 7 5 1 4


// 1 2 3 4 5 6 7 -> 1 2 4 5 6 7 3 == 3
// 1 2 3 4 5 6 7 -> 1 2 4 5 7 3 6 1 2 3 4 5== 3 6
// 1 2 3 4 5 6 7 -> 1 2 4 5 6 7 == 3
