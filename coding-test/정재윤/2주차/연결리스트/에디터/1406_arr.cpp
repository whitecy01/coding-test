#include <bits/stdc++.h>
using namespace std;

const int MX = 600100;
char dat[MX];
int pre[MX], nxt[MX];
int unused = 1;
int cursor = 0;

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
      cout << dat[cur];
      cur = nxt[cur];
    }
  }

int main(void) {
  fill(pre, pre+MX, -1);
  fill(nxt, nxt+MX, -1);
  string str;
  cin >> str;
  for (int i = 0; i < str.size(); i++)
  {
    insert(i, str[i]);
    cursor++;
  }

    int n;
  cin >> n;
  for (int i = 0; i < n; i++)
  {
    char temp;
    cin >> temp;
    if (temp == 'L'){
        // cursor = pre[];
        if (pre[cursor] != -1){
            cursor = pre[cursor];
        }
    }
    else if (temp == 'D'){
        if (nxt[cursor] != -1){
            cursor = nxt[cursor];
        }
    }
    else if (temp == 'B'){
        if (pre[cursor] != -1){
            erase(cursor);
            cursor = pre[cursor];
        }
    }
    else if (temp == 'P'){
        char en;
        cin >> en;
        insert(cursor, en);
        cursor = nxt[cursor];
    }
  }
  
  traverse();

  
}