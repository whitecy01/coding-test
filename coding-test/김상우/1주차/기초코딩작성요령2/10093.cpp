/*
    10^15 이니까 long long 으로 쓰고. a , b에 입력값 넣어주고 어제 배운 algorith 에 swap 함수 써서
    굳이 배열 쓰거나 코드 길게 짜지 말고 그냥 단순하게 바꿔주면서 b를 항상 a보다 높은 순으로 배치해서
    b - a 하면? 두 수 사이의 값들의 수를 출력. 그 다음 열에 b보다 작은 수들을 출력 i에 a+1값을 넣어서
    a보다 크고 i 가 b보다 작음으로 두 수 사이의 값들을 출력해준는 식으로 했는데 뭐지 안되네/
    ../....???????? 아 b가 7이고 a가 6이면.. 사이 정수가...아 0이네 그러면 b-a-1..? 해야하나
    b가 8이고 a가 6이면 8-6 = 2 아. -1 넣어주도록 하자..
    그러면 b와 a가 같은경우에는 음수가 나와버리기 때문에. b와 a가 같은경우 if문으로 0출력하고 바로 return 0
    시킬 예정. 끝. 이제 돌려보면? 굿.
*/


#include<iostream>
#include<algorithm>

using namespace std;

int main(){

        long long a, b;
        cin >> a >> b;

        if(a > b){
            swap(a,b);
        }

        if(a == b){
            cout << 0;
            return 0;
        }else{
            cout << b - a - 1 << "\n";

            for (long long i = a + 1; i < b; i ++) {
                cout << i << " ";
            }
        }

        return 0;
}
