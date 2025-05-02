// #include <iostream>
// #include <string>
// #include <stack>
// using namespace std;

// int main() {
//     string str;
//     cin >> str;

//     stack<char> s;
//     int count = 0;     
//     int result = 0;       

//     for (int i = 0; i < str.size(); i++) {
//         char c = str[i];

//         if (c == '(') {
//             s.push('(');
//             count++; 
//         } else {
//             s.pop();  
//             count--; 

//             if (str[i - 1] == '(') {
               
//                 result += count * 2;
//             } else {
//                 result += 1;
//             }
//         }
//     }

//     cout << result << '\n';
//     return 0;
// }

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    string str;
    cin >> str;

    stack<char> s;
    int result = 0;

    for (int i = 0; i < str.size(); i++) {
        char c = str[i];

        if (c == '(') {
            s.push(c);
        } else {

            s.pop();

            if (str[i - 1] == '(') {
                result += s.size();
            } else {
                result += 1;
            }
        }
    }

    cout << result << '\n';
    return 0;
}
