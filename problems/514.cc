#include <iostream>
#include <stack>
#include <vector>
using namespace std;
typedef vector<int> Vi;
int main() {
  int n;
  bool first = true;
  while (cin >> n and n) {
    
    int k;
    Vi v(n);
    while (cin >> k and k) {
      v[0] = k;
      for (int i = 1; i < n; ++i)
        cin >> v[i];
      
      stack<int> s;
      int ind = 0;
      for (int i = 1; i <= n; ++i) {
        s.push(i);
        while (!s.empty() and s.top() == v[ind]) {
          s.pop();
          ++ind;
        }
      }
      if (s.empty()) cout << "Yes" << endl;
      else cout << "No" << endl;
    }
    cout << endl;
  }
}