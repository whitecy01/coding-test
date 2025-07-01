#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n,m;
int arr[10];

vector<int> V;
bool isused[10];

void func(int k){
    if (k == m){
        for (int i = 0; i < m; i++)
        {
            cout << arr[i] << " ";
        }
        cout << "\n";
        return; 
    }

    for (int i = 1; i <= n; i++)
    {
        if (!isused[i]){

            arr[k] = V[i - 1];
            isused[i] = 1;
            func(k + 1);
            isused[i] = 0;
        }
    }
    
}

int main(){
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        V.push_back(temp);
        // cin >> V[i];
    }
    sort(V.begin(), V.end());
    
    func(0);
}