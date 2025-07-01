#include <iostream>
#include <algorithm>
using namespace std;

int n,m;
int arr[10];
bool isused[10];
int num[10];

void func(int k){
    if (k == m){
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return ;
    }

    int tmp = 0;
    for (int i = 0; i < n; i++)
    {
        if (!isused[i] && tmp != num[i]){
            isused[i] = true;
            arr[k] = num[i];
            tmp = arr[k];
            func(k + 1);
            isused[i] = false;
        }
    }
    
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> num[i];
    }
    sort(num, num + n);
    func(0);
    
}