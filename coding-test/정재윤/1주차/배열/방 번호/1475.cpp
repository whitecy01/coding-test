#include <iostream>
#include <algorithm>
using namespace std;


int arr[10] = {0};
int main(){
    string str;
    cin >> str;

    for (int i = 0; i < str.size(); i++)
    {
        arr[str[i] - '0']++;
    }
    int six,nine;
    six = arr[6];
    nine = arr[9];
    int temp = six + nine;
    // for (int i = 0; i < 10; i++)
    // {
    //     cout << arr[i] << " ";
    // }
    if (temp % 2 == 0){
        arr[6] = arr[9] = temp / 2;
    }
    else {
        arr[6] = arr[9] = temp / 2 + 1;
    }

    int ans = 0;

    for (int i = 0; i < 10; i++)
    {
        ans = max(ans, arr[i]);
    }
    cout << ans << "\n";   
}