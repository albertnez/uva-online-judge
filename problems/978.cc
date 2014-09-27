#include <iostream>
#include <set>
using namespace std;

int main() {
  int T; cin >> T;
  
  while (T--) {
    int b, ng, nb;
    cin >> b >> ng >> nb;
    multiset<int> sg, sb;
    for (int i = 0; i < ng; ++i) {
      int k; cin >> k;
      sg.insert(k); 
    }
    for (int i = 0; i < nb; ++i) {
      int k; cin >> k;
      sb.insert(k);
    }
    
    while (!sg.empty() and !sb.empty()) {
      multiset<int> cg, cb;
      multiset<int>::reverse_iterator ig = sg.rbegin(), ib = sb.rbegin();

      int steps = 0;
      while (steps < b and ig != sg.rend() and ib != sb.rend()) {
        int k = *ig-*ib;
        if (k > 0) cg.insert(k);
        else if (k < 0) cb.insert(-k);

        sg.erase(--ig.base());
        sb.erase(--ib.base());
       
        ++steps;
      }
      for (ig = cg.rbegin(); ig != cg.rend(); ++ig) sg.insert(*ig);
      for (ib = cb.rbegin(); ib != cb.rend(); ++ib) sb.insert(*ib);
    }
    
    if (!sg.empty()) {
      cout << "green wins" << endl;
      for (multiset<int>::reverse_iterator it = sg.rbegin(); it != sg.rend(); ++it) cout << *it << endl;
    }
    else if (!sb.empty()) {
      cout << "blue wins" << endl;
      for (multiset<int>::reverse_iterator it = sb.rbegin(); it != sb.rend(); ++it) cout << *it << endl;
    }
    else cout << "green and blue died" << endl;
    
    if (T) cout << endl;
  }
  
}