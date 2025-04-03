#include <iostream>
#include <string>
using namespace std;

int main(){

    string apl;
    cin >> apl;

    int count[30] = {0};

    for(char c : apl)
        count[c-'a']++;

    for(int i=0;i < 26; i++)
        cout << count[i] << " ";

    return 0;
}