#include<iostream>
    using namespace std;
int main(){
    int a;
    cin >> a;

    if(a >=90 && a <= 100){
        cout << "A";
    }else if(a<=89 && a>=80){
        cout << "B";

    }else if(a<=79 && a>=70){
        cout << "C";
    }else if(a<=69 && a>=60){
        cout << "D";
    }else{
        cout << "F";
    }

    return 0;
}