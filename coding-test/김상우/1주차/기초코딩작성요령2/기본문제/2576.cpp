/*
7개의 자연수가 입력값으로 주어지기에 for문을 7번 횟수로 돌릴예정.
이들 중 자연수들을 모두 골라 그 합을 구한다. 홀수가 없으면 -1 출력 홀수가 있으면 홀수들의 합 출력
그리고 그중 가장 작은 값을 구해야한다. 이는 매우 쉬움. 일단 7번 돌리면서 변수값에 최소값을 정해줄 예정임.
매우 다행이게도 100이하의 수기 때문에 변수값에 100을 넣고 하나씩 돌려보며 100보다 작으면 오버라이딩
그리고 홀수가 없을 경우를 생각해서 조건문 추가..?

*/

#include <iostream>

using namespace std;

int main(){
    int num ;
    int sum = 0;
    int min = 100;
    for(int i = 0; i < 7;i++){
        cin >> num;
        if(num % 2 == 1){
            sum = sum + num;
            if(num < min){
                min = num;
            }
        }

    }if(sum > 0){
        cout << sum << "\n" << min << "\n";
    }else{
        cout << -1;
    }


}