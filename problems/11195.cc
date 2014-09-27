#include <iostream>
using namespace std;
int N;
int count = 0;
int OK;
int bad[15];
void bt(int i, int rw, int ld, int rd) {
  if (i == N) {
    if (rw == OK) 
      ++count;
  }   
  else {
    int pos = OK & (~bad[i]) & (~(rw|ld|rd)); 
    while (pos) {
      int p = pos & -pos;
      bt(i+1, rw | p, (ld | p) << 1, (rd | p) >> 1);
      pos -= p;
    }
  }
}

int main() {
  int n;
  int ncase = 0;
  while (cin >> n and n) {
    N = n;
    count = 0;
    OK = (1<<n)-1;
    string s[n];
    for (int i = 0; i < n; ++i) {
      cin >> s[i];
      bad[i] = 0;
    }
    for (int i = 0; i < n; ++i)
      for (int j = 0; j < n; ++j)
        if (s[j][i] == '*')
          bad[i] |= (1<<j);
    bt(0, 0, 0, 0);
    cout << "Case " << ++ncase << ": " << count << endl;
  }
}
