#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;

int main() {
  int T; cin >> T;
  while (T--) {
    int n; cin >> n;
    Vi v(n);
    int sol = 0;
    for (int i = 0; i < n; ++i) {
      cin >> v[i];
      for (int j = 0; j < i; ++j)
	if (v[j] <= v[i])
	  ++sol;
    }
    cout << sol << endl;      
  }
}