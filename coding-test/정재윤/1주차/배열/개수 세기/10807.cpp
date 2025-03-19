#include <iostream>
#include <algorithm>
using namespace std;


int arr[500] = {0};
int main(){
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int temp;
        cin >> temp;
        if (temp < 0){
            temp = abs(temp) + 100;
        }
        arr[temp]++;
    }
    int v; 
    cin >> v;
    if (v < 0){
        v = abs(v) + 100;
    }
    cout << arr[v] << "\n";
}