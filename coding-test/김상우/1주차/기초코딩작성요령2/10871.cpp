//X보다 작은 수

#include <iostream>

using namespace std;

int main(){
    int n , x;
    cin >> n >> x;

    int ans;

    for(int i = 0; i < n; i++){

        cin >> ans;

        if(ans < x){
            cout << ans << " ";
        }
        
    }

    return 0;
}