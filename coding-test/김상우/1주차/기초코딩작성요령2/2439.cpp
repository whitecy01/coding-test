
/*
    n이 5일때 1열에 공백이 4번찍혀야 하나?
    그럼 n-i번? 잉 아니네? 그냥 n번?
        j = n i보다 클때까지 1씩 감소시키면

        n이 5이고 i가 1일때 5 4 3 2 4번 굿.

*/






#include <iostream>

using namespace std;

int main(){

    int n;
    cin >> n;

    for(int i=1;i<=n;i++){
        for(int j =n;j>i;j--){
            cout << " ";

            
        }
        for(int z = 1; z <= i;z++){
            cout << "*";
        }
        cout << "\n";

    }

    return 0;
}