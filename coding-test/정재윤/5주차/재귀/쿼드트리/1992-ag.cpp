
























#include <iostream>

using namespace std;

string arr[65];

bool check(int a, int b, int size){
    char num = arr[a][b];
    for (int i = a; i < a + size; i++) {
        for (int j = b; j < b + size; j++) {
            if (arr[i][j] != num)
                return false;
        }
    }
    return  true;
}


void func(int a, int b, int size){
    if (check(a, b, size)){
        cout << arr[a][b];
        return;
    }

    cout << '(';  // 시작 괄호

    int newSize = size / 2;
    // cout<< "a : " << a << " b :" << b << "\n";
    func(a, b, newSize);                     // 왼쪽 위
    func(a, b + newSize, newSize);           // 오른쪽 위
    func(a + newSize, b, newSize);           // 왼쪽 아래
    func(a + newSize, b + newSize, newSize); // 오른쪽 아래

    cout << ')';  // 닫는 괄호

}


int main(){
    int N;
    cin >> N;
    
    for (int i = 0; i < N; i++)
    {
        cin >> arr[i];
        
    }
    func(0,0,N);

}