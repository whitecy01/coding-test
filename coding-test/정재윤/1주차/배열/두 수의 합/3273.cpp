#include <iostream>

using namespace std;


int arr[1000003] = {0};
int a[1000003] = {0};
int main(){
    int n;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    int com;
    cin >> com;
    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        if (com - arr[i] > 0 && a[com - arr[i]] == 1) {
            ans++;
        }

        a[arr[i]] = 1;
    }
    cout << ans;
    
    
}