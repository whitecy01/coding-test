#include <iostream>

using namespace std;

int arr[10];
int n,m;

void func(int k){
    if (k == m){
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return ;
    }

    int st = 1;
    if (k != 0) st = arr[k - 1] + 1;
    for (int i = st; i <= n; i++)
    {
        arr[k] = i; 
        func(k + 1);
    }
    
}

int main(){
    cin >> n >> m;
    func(0);
}