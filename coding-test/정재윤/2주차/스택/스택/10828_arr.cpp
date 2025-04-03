#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX];
int pos = 0;

void push(int x){
  dat[pos] = x;
  pos++;
}

void pop(){
  pos--;
}

int top(){
  return dat[pos - 1];
}


int main(void) {
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
      string temp;
      cin >> temp;
      if (temp == "push"){
          int te;
          cin >> te;
          push(te);
      }
      else if (temp == "top"){
          if (pos == 0){
              cout << "-1\n";
          }
          else {
              cout << top() << "\n";
          }
      }
      else if (temp == "pop"){
          if (pos == 0){
              cout << "-1\n";
          }
          else {
              cout << top() << "\n";
              pop();
          }
      }
      else if (temp == "size"){
          cout << pos << "\n";
      }
      else if (temp == "empty"){
          if (pos == 0){
              cout << "1\n";
          }
          else 
              cout << "0\n";
      }
  }
}