#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> Vi;
typedef vector<Vi> Mi;
int main() {
  int n;
  bool first = true;
  while (cin >> n and n) {
    if (first) first = false;
    else cout << endl;
    
    Vi v(n);
    for (int i = 0; i < n; ++i)
      cin >> v[i];
    
    sort(v.begin(), v.end());
    
    int maxsize = 0;
    int old = -1;
    int tmp = 0;
    for (int i = 0; i < n; ++i) {
      if (v[i] == old) {
        ++tmp;
      }
      else {
        maxsize = max(maxsize, tmp);
        old = v[i];
        tmp = 1;
      }
    }
    maxsize = max(maxsize, tmp);
    
    Mi bags(maxsize);
       
    for (int i = 0; i < n; ++i) 
      bags[i%maxsize].push_back(v[i]);
    
    cout << maxsize << endl;
    for (int i = 0; i < maxsize; ++i) {
      for (int j = 0; j < bags[i].size(); ++j)
        cout << (j? " ":"") << bags[i][j];
      cout << endl;
    }
  }
}