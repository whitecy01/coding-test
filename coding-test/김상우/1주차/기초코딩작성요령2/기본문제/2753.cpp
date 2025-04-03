/* 4의 배수면서 100의 배수가 아니지만 그중에서 400의 배수일때. 가 윤년이다? 맞나? 일단 이대로 if , elif 문 작성. 그리고 1900 넣어봄 0 굿 2000 넣어봄 1 굿.
  1911 넣어봄... ? 아무 것도 출력안됨. 머여 하고 봤더니. if(a % 4 ==0) 에서만 출력됨 ㅋㅋㅋㅋㅋㅋㅋㅋ 그래서 else문 하나 넣어줌. */


#include<iostream>
using namespace std;

int main(){

    int a;
    cin >> a;
 
    if(a % 4 == 0){
        if(a % 100 != 0){
            cout << 1;
        }else if(a % 400 == 0){
            cout << 1;
        }else{
            cout << 0;
        }
    }else{
        cout << 0;
    }


    return 0;
}