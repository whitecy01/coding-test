#include <iostream>
#include <list>
#include <string>
using namespace std;

int main(){
    
    string str;
    cin >> str;
    
    list<char> cd;
    for(char c : str){
        cd.push_back(c);
    }

    list<char>::iterator cursor = cd.end();

    int M;
    cin >> M;

   for(int i =0; i < M; i++){
        char cmd;
        cin >> cmd;


        if(cmd == 'L'){
            if(cursor != cd.begin()){
                --cursor;
            }
        }
        else if(cmd == 'D'){
            if(cursor != cd.end()){
                ++cursor;
            }
        }
        else if(cmd == 'B'){
            if(cursor != cd.begin()){
                --cursor;
                cursor = cd.erase(cursor); //이게 뭔데..?
            }
        
        }else if(cmd == 'P'){
            char x;
            cin >> x;
            cd.insert(cursor, x);
        }
    }

    for (char ch : cd){
        cout << ch;
    }

    return 0;
}