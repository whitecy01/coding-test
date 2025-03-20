/* 입력으로 1이 들어오면 +1 0이 들어오면 그냥 ㄱ 이런식으로 코드 작성해보자. 문제는 다음 열인데..?일단 하드 코딩 ㄱㄱ
배 = 0 등 = 1 / 등 3 = 도A 등 2 = 개B 등 4 = 모E 등 0 = 윷D*/

#include <iostream>
using namespace std;

int main(){
    int arr[4];
    int cnt;

    for(int i =0;i <3;i++){
        cnt = 0;
        for(int j = 0; j <4;j++){
            cin >> arr[j];
            if(arr[j]==1){
                cnt ++;
            }
        }
        if(cnt == 4){
            cout << "E" << "\n";
        }else if(cnt == 3){
            cout << "A" << "\n";
        }else if(cnt == 2){
            cout << "B" << "\n";
        }else if(cnt == 1){
            cout << "C" << "\n";
        }else{
            cout << "D" << "\n";
        
     }
    }

    return 0;
}