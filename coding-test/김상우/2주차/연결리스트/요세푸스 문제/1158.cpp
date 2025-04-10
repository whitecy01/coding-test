#include <iostream>
#include <list>

using namespace std;

int main(){
    int n, k; // n : 사람 수 , k : 제거될 다음 순번
    cin >> n >> k;

    list<int>pl;
    for(int i =1;i <=n;i++){
        pl.push_back(i);
    }

    list<int>::iterator it = pl.begin();
    cout << "<";


    for (int i =0; i < n; i++){
        for(int j =1; j < k; j++){
            it++;
            if(it == pl.end()){
                it = pl.begin();
            }
        }

        cout << *it;

        it = pl.erase(it);
        if(it == pl.end()){
            it = pl.begin();
        }
        if(i != n -1) cout << ", ";
    }

    cout << ">\n";
    return 0;
}