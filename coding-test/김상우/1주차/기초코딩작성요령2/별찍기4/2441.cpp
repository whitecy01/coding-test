#include <iostream>

using namespace std;

int main(){
    int n;
    cin >> n;

    for(int i =n;i>=0;i--){
        for(int j = 0; j <n-i;j++ ){
            cout << " ";
        }
        for(int z =0; z < i;z++){
            cout << "*";
        }

        cout <<"\n";
    }



}