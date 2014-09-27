#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;

const int n = 26;

int main() {
  string s;
  int ncase = 0;
  while (getline(cin, s) and s != "end") {
    Vi v;
    for (int i = 0; i < s.size(); ++i) {
      int k = s[i]-'A';
      int best = -1;
      int val = n;
      for (int j = 0; j < v.size(); ++j) {
        if (v[j] >= k and v[j] < val) {
          val = v[j];
          best = j;
        }
      }
      if (val != n) v[best] = k;
      else v.push_back(k);
    } 
    cout << "Case " << ++ncase << ": " << v.size() << endl;
  }
}