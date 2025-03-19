#include <iostream>

using namespace std;

int arr_a[26] = {0};
int arr_b[26] = {0};

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    string a, b;
    cin >> a >> b;
    for (int i = 0; i < a.size(); i++)
    {
        arr_a[a[i] - 'a']++;
    }

    for (int i = 0; i < b.size(); i++)
    {
        arr_a[b[i] - 'a']--;
    }
    for (int i = 0; i < 26; i++)
    {
        ans += abs(arr_a[i]);
    }
    cout << ans<<"\n";
}