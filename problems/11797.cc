#include <iostream>
#include <vector>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

const int N = 5;
string names[N] = {"Ja", "Sam", "Sha", "Sid", "Tan"};
int times[N] = {0,0,0,0,0};

int f(const string &s) {
  for (int i = 0; i < N; ++i)
    if (names[i] == s) return i;
}

int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    for (int i = 0; i < N; ++i) times[i] = 0;
    int m, n, act;
    string s;
    cin >> m >> n >> s;
    act = f(s);
    
    vector<queue<int> > vq(N);
    for (int i = 0; i < N; ++i) {
      int num; cin >> num;
      while (num--) {
        string name; cin >> name;
        vq[i].push(f(name));
      }
    }
    
    
    int t = 0;
    while (t < n) {
      times[act] += min(m, n-t);
      t += m+2;
      int nact = vq[act].front();
      vq[act].push(nact);
      vq[act].pop();
      act = nact;
    }
    
    cout << "Case " << ++ncase << ":" << endl;
    for (int i = 0; i < N; ++i) 
      cout << names[i] << ' ' << times[i] << endl;
  }
}