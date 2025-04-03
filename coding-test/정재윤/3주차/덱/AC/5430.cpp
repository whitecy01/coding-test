#include <iostream>
#include <deque>
#include <algorithm>
#include <string>
#include <sstream>
#include <iterator>

using namespace std;


deque<int> split(string arr, char search){
    istringstream ss(arr);
    string word;

    deque<int> num;
    while (getline(ss, word, search))
    {
        // cout << word<<"\n";
        num.push_back(stoi(word));
    }
    return num;
}

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        string str;
        cin >> str;
        int size;
        cin >> size;

        string arr;
        cin >> arr;
        string pashre_arr = arr.substr(1, arr.size() - 2);
        // cout << pashre_arr << "\n";
        deque<int> vec = split(pashre_arr, ',');
        // for (auto here : vec)
        // {
        //     cout << here << "\n";
        // }
        bool check = true;
        bool isReversed = false;
        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == 'R'){
                isReversed = !isReversed;
            }
            else if (str[i] == 'D'){
                if (vec.empty()){
                    check = false;
                    cout << "error\n";
                    break;
                }
                if (isReversed){
                    vec.pop_back();
                }
                else vec.pop_front ();
            }
        }
        if (check == true){
            cout << "[";
            if (isReversed) {
                for (auto it = vec.rbegin(); it != vec.rend(); ++it) {
                    cout << *it;
                    if (it + 1 != vec.rend()) cout << ",";
                }
            } else {
                for (auto it = vec.begin(); it != vec.end(); ++it) {
                    cout << *it;
                    if (it + 1 != vec.end()) cout << ",";
                }
            }
            // for (int idx = 0; idx < vec.size(); idx++)
            // {
            //     cout << vec[idx];
            //     if (idx != vec.size() - 1)
            //         cout << ",";
            // }
            cout <<"]\n";
            
        }

        
    }
}

// #include <iostream>
// #include <deque>
// #include <algorithm>
// #include <string>
// #include <sstream>
// #include <iterator>

// using namespace std;


// deque<int> split(string arr, char search){
//     istringstream ss(arr);
//     string word;

//     deque<int> num;
//     while (getline(ss, word, search))
//     {
//         // cout << word<<"\n";
//         num.push_back(stoi(word));
//     }
//     return num;
// }

// int main(){
//     ios::sync_with_stdio(false);
//     cin.tie(0);
//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         string str;
//         cin >> str;
//         int size;
//         cin >> size;

//         string arr;
//         cin >> arr;
//         string pashre_arr = arr.substr(1, arr.size() - 2);
//         // cout << pashre_arr << "\n";
//         deque<int> vec = split(pashre_arr, ',');
//         // for (auto here : vec)
//         // {
//         //     cout << here << "\n";
//         // }
//         bool check = true;
//         for (int i = 0; i < str.size(); i++)
//         {
//             if (str[i] == 'R'){
//                 reverse(vec.begin(), vec.end()); // 이 부분
//                 // for (auto here : vec)
//                 // {
//                 //     cout << here << "\n";
//                 // }
//             }
//             else if (str[i] == 'D'){
//                 if (!vec.empty()){
//                     vec.pop_front();
//                 }
//                 else 
//                 {
//                     check = false;
//                     cout << "error\n";
//                     break;
//                 }
//             }
//         }
//         if (check == true){
//             cout << "[";
//             for (int idx = 0; idx < vec.size(); idx++)
//             {
//                 cout << vec[idx];
//                 if (idx != vec.size() - 1)
//                     cout << ",";
//             }
//             cout <<"]\n";
            
//         }

        
//     }
    


// }