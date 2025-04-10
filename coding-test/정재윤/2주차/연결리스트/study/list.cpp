#include <iostream>
#include <list>
#include <algorithm>
using namespace std;

int main(){
    list<int> li;

    li.push_back(1);
    li.push_back(2);
    li.push_back(3);
    li.push_back(4);

    list<int>::iterator iter = li.end();

    iter--;
    iter--;
    iter--;
    cout << *iter<<"\n";
    cout << &iter <<"\n";

    iter = li.erase(iter);

    cout << *iter<<"\n";
    cout << &iter <<"\n";

    

}