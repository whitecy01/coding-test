/*
100보다 작은 10의 배수 값으로 다섯개의 자연수가 입력값으로 주어진다라. 즉 for문을 통해 5번 돌려.
num에다가 입력값 받아주고 받는 족족 avg에 더해 그리고 크기 순서대로 배치해서 중앙값을 구해야한다.
라는 것은? 크기 순서대로 배치해서 중앙에 위치해야 하기 때문에 arr[2] 값을 가져오면 될듯?
근데 크기 순서대로 배치를 어떵하지 흠.
2중 for?
arr[0] arr[1] / arr[1] arr[2] ... 두개씩 확인
하고 출력.. 근데 시간초과 뜸 ㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋㅋ 잠만.
아.. j범위를 6으로 둬서 그런듯? arr[5]에 접근할려하니 없으니 그러지 에휴. 정답.
*/

#include <iostream>

using namespace std;

int main(){
    int avg = 0; 
    int a;
    int b;
    int arr[5];
    for(int i=0;i<5;i++){
        cin >> arr[i];
        avg = avg + arr[i];
    }
    for(int i = 0; i < 4;i++){
        for(int j = i+1;j <5; j++){
            if(arr[i] > arr[j]){
                a = arr[i];
                arr[i] = arr[j];
                arr[j] = a;
            }
        }
    }
    b = arr[2];
    cout << avg/5 << "\n" << b;

}