#include <bits/stdc++.h>
using namespace std;

const int MX = 1000005;
int dat[MX], pre[MX], nxt[MX];
int unused = 1;

// void insert(int addr, int num){
//     dat[unused] = num; // 제일 마지막에 공간에 있는 부분에 값 넣기
//     if (nxt[addr] == -1){
//         pre[unused] = addr;
//     }
//     else {
//         pre[unused] = pre[nxt[addr]];
//         pre[nxt[addr]] = unused;    
//     }

//     if (nxt[addr] == -1)
//         nxt[unused] = -1;
//     else
//         nxt[unused] = nxt[addr];
//     nxt[addr] = unused; // addr의 nxt
//     unused++;
// }

void insert(int addr, int num){
    dat[unused] = num; // 제일 마지막에 공간에 있는 부분에 값 넣기
    pre[unused] = addr;
    nxt[unused] = nxt[addr];
    if (nxt[addr] != -1) pre[nxt[addr]] = unused;
    nxt[addr] = unused;
    unused++;
}

void erase(int addr){
    //1. 이전위치의 nxt 값을 삭제할 nxt값으로 변경
    nxt[pre[addr]] = nxt[addr];
    //2. 앞 위치의 pre 값을 삭제할 pre값으로 변경
    if (nxt[addr] != -1 ) pre[nxt[addr]] = pre[addr];
    
}

void traverse(){
  int cur = nxt[0];
  while(cur != -1){
    cout << dat[cur] << ' ';
    cur = nxt[cur];
  }
  cout << "\n\n";
}

void insert_test(){
  cout << "****** insert_test *****\n";
  insert(0, 10); // 10(address=1)
  traverse();
  insert(0, 30); // 30(address=2) 10
  traverse();
  insert(2, 40); // 30 40(address=3) 10
  traverse();
  insert(1, 20); // 30 40 10 20(address=4)
  traverse();
  insert(4, 70); // 30 40 10 20 70(address=5)
  traverse();
}

void erase_test(){
  cout << "****** erase_test *****\n";
  erase(1); // 30 40 20 70
  traverse();
  erase(2); // 40 20 70
  traverse();
  erase(4); // 40 70
  traverse();
  erase(5); // 40
  traverse();
}

int main(void) {
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  insert_test();
  for (int i = 0; i < unused; i++)
  {
    cout << dat[i] << " ";
  }
  cout << "\n";
  for (int i = 0; i < unused; i++)
  {
    cout << pre[i] << " ";
  }
  cout << "\n";
  for (int i = 0; i < unused; i++)
  {
    cout << nxt[i] << " ";
  }
  cout << "\n";
  erase_test();
}