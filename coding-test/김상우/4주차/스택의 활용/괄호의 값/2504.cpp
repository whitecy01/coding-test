#include <iostream>   
#include <stack>     
#include <string>     
using namespace std;

int main() {
    string str;
    cin >> str; 

    stack<char> s;     
    stack<int> value;   

    bool valid = true; 

    
    for (char c : str) {
        if (c == '(' || c == '[') {

            s.push(c);
            value.push(0);
        } else {
        
            if (s.empty()) {
                valid = false;
                break;
            }

            char top = s.top(); 
            s.pop();            

            int temp = 0;

            
            while (!value.empty() && value.top() != 0) {
                temp += value.top();
                value.pop();
            }

            
            if (value.empty()) {
                valid = false;
                break;
            }

            value.pop(); 

           
            if (c == ')' && top == '(') {
               
                value.push(temp == 0 ? 2 : 2 * temp);
            } else if (c == ']' && top == '[') {
               
                value.push(temp == 0 ? 3 : 3 * temp);
            } else {
                
                valid = false;
                break;
            }
        }
    }

 
    if (!valid || !s.empty()) {
        cout << 0 << '\n';
    } else {
        int result = 0;

       
        while (!value.empty()) {
            result += value.top();
            value.pop();
        }

        cout << result << '\n';
    }

    return 0;
}
