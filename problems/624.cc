#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> w;
vector<bool> v, sol;
int best;

void f(int i, int n) {
  if (i == N) {
    if (n > best) {
      best = n;
      sol = v;
    }
  }
  else {
    f(i+1, n);
    if (n+w[i] <= M) {
      v[i] = true;
      f(i+1, n+w[i]); 
      v[i] = false;
    }
  }
}

int main() {
  while (cin >> M >> N) {
    v.assign(N, false);
    w.assign(N, 0);
    best = 0;
    for (int i = 0; i < N; ++i)
      cin >> w[i];
    f(0, 0);
    for (int i = 0; i < N; ++i) 
      if (sol[i]) cout << w[i] << ' ';  
    cout << "sum:" << best << endl;
    
  }
    
}