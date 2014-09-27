#include <iostream>
#include <vector>
#include <sstream>
#include <queue>
#include <algorithm>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;

const int maxn = 26;

int main() {
  string line;
  while (getline(cin,line) and line != "#") {
    MI G(maxn);
    MI adj(maxn, VI(maxn, 0));

    int pos = 0;
    while (line[pos] != '.') {
      if (line[pos] >= 'A' and line[pos] <= 'Z') {
        int u = line[pos]-'A';
        ++pos;
        while (line[pos] < 'A' or line[pos] > 'Z') ++pos;
        while (line[pos] != '.' and line[pos] != ';') {
          if (line[pos] >= 'A' and line[pos] <= 'Z') {
            int v = line[pos]-'A';
            if (!adj[u][v] and u!=v) {
              adj[u][v] = adj[v][u] = 1;
              G[u].push_back(v);
              G[v].push_back(u);
            }
          }
          ++pos;          
        }
      }
      else ++pos;
    }
    while (line[pos] < 'A' or line[pos] > 'Z') ++pos;
    int pask = line[pos]-'A'; 
    ++pos;
    while (line[pos] < 'A' or line[pos] > 'Z') ++pos;
    int lisp = line[pos]-'A';
    ++pos;
    
    for (int i = 0; i < maxn; ++i)
      sort(G[i].begin(), G[i].end()); 
    
    vector<bool> vlisp(maxn, false), vpask(maxn, false);
    int paskNext = 0, lispNext = 0;
    
    while (paskNext != -1 and lispNext != -1 and !vpask[lisp] and lisp != pask) {
      paskNext = lispNext = -1;
      
      vlisp[lisp] = true;
      vpask[pask] = true;
      
      for (int i = 1; i < maxn and paskNext == -1; ++i) {
        int x = (pask+i)%maxn;
        if (adj[pask][x] and !vlisp[x] and !vpask[x])
          paskNext = x;
      }
      for (int i = maxn-1; i > 0 and lispNext == -1; --i) {
        int x = (lisp+i)%maxn;
        if (adj[lisp][x] and !vlisp[x])
          lispNext = x;
      }
      
      if (paskNext != -1) pask = paskNext;
      if (lispNext != -1) lisp = lispNext;
    }
    
    if (paskNext == -1) {
      cout << "Paskill trapped in node " << char('A'+pask);
      if (lispNext == -1 or vpask[lisp] or pask == lisp) cout << ' ';
    }
    if (lisp == pask) cout << "Both annihilated in node " << char('A'+pask);   
    else if (lispNext == -1) cout << "Lisper trapped in node " << char('A'+lisp);
    else if (vpask[lisp]) cout << "Lisper destroyed in node " << char('A'+lisp); 
    cout << endl;
  }
}