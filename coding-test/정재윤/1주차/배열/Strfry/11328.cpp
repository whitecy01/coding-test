#include <iostream>

using namespace std;


int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
  
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int arr_a[26] = {0};
        int arr_b[26] = {0};
        string a, b;
        cin >> a >> b;
        bool check = true;
        for (int j = 0; j < a.size(); j++)
        {
            arr_a[a[j] - 'a']++;
        }
        for (int j = 0; j < b.size(); j++)
        {
            arr_b[b[j] - 'a']++;    
        }
        for (int k = 0; k < 26; k++)
        {
            if (arr_a[k] - arr_b[k] != 0){
                cout << "Impossible" << "\n";
                check = false;
                break;
            }
        }

        if (check == true)
            cout << "Possible" << "\n";
        
    }
}

// #include <iostream>

// using namespace std;


// int main(){
//     ios::sync_with_stdio(0);
//     cin.tie(0);
  
//     int n;
//     cin >> n;

//     for (int i = 0; i < n; i++)
//     {
//         int arr_a[26] = {0};
//         string a, b;
//         cin >> a >> b;
//         bool check = true;
//         for (int j = 0; j < a.size(); j++)
//         {
//             arr_a[a[j] - 'a']++;
//         }
//         for (int j = 0; j < b.size(); j++)
//         {
//             if (arr_a[b[j] - 'a'] == 0){
//                 cout << "Impossible" << "\n";
//                 check = false;
//             }
//         }
//         if (check == true)
//             cout << "Possible" << "\n";
        
//     }
// }