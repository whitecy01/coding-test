#include <iostream>

using namespace std;

void func(int n){
    if (n == 0)
        return;
    func(n - 1);
}

int main(){
    func(100000);
    cout << "done\n";

}