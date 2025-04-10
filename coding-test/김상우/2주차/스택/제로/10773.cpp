#include <iostream>
#include <stack>

using namespace std;

int main(){
    int N;
    cin >> N;


    stack<int> s;

    for (int i =0; i < N; i++){
        int num;
        cin >> num;


        if(num ==0){
            if(!s.empty()){
                s.pop();
            }
        }else{
            s.push(num);
        }


    }

    int sum = 0;

    while(!s.empty()){
        sum += s.top();
        s.pop();
    }

    cout << sum << "\n";

    return 0;
}