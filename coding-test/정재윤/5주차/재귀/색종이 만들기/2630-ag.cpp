#include <iostream>

using namespace std;

int arr[129][129];

int result[3] = {0};

bool check(int a, int b, int size){
    int num = arr[a][b];
    for (int i = a; i < a + size; i++)
    {
        for (int j = b; j < b + size; j++)
        {
            if (num != arr[i][j])
                return false;
        }
    }
    return true;
}

void func(int a, int b, int size){
    if (check(a, b, size)){
        result[arr[a][b]]++;
        return ; 
    }

    int num = size / 2;
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            func(a + i * num, b + j * num, num);
        }
    }
}

int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> arr[i][j];
        }
    }

    func(0,0, n);
    for (int i = 0; i < 2; i++)
    {
        cout << result[i] << "\n";
    }
    
    
}