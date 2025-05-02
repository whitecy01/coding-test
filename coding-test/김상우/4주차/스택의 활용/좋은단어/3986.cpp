#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    int N;
    cin >> N;

    int count = 0;

    for (int i = 0; i < N; i++) {

        string word;
        cin >> word;

        stack<char> s;

        for(int j =0; j < word.size(); j++){
            char c = word[j];

            if(!s.empty()&&s.top() == c){
                s.pop();
            }else{
                s.push(c);
            }


        }

        if(s.empty()){
            count++;
        }



    }

    cout << count << '\n';
    return 0;
}
