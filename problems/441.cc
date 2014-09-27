#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;

void print(const Vi &v, const Vi &w) {
  for (int i = 0; i < 6; ++i)
    cout << (i?" ":"") << v[w[i]];
  cout << endl;
}

int main() {
  int k; 
  bool first = true;
  while (cin >> k and k) {
    if (first) first = false;
    else cout << endl;
    
    Vi v(k), w(7);
    for (int i = 0; i < 6; ++i)
      w[i] = i;
    w[6] = k;
    for (int i = 0; i < k; ++i) 
      cin >> v[i];
    
    bool pos = true;
    
    while (pos) {
      int ind = 5;
      print(v,w);
      pos = false;
      while (!pos and ind >= 0) {
	if (w[ind]+1 < w[ind+1]) {
	  pos = true;
	  w[ind]++;
	}
	else --ind;
      }
      while (pos and ++ind < 6)
	w[ind] = w[ind-1]+1;
    }
  }
}