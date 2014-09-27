#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> Vi;
int cti(char c) {
  if (c >= 'a' and c <= 'z') return (c-'a')*2+1;
  return (c-'A')*2;
}

char itc(int i) {
  if (i&1) return 'a'+i/2;
  return 'A'+i/2;
}

void print(const Vi &v) {
  for (int i = 0; i < v.size(); ++i)
    cout << itc(v[i]);
  cout << endl;
}
int main() {
  int n; cin >> n;
  while (n--) {
    string s;
    cin >> s;
    Vi v(s.size());
    for (int i = 0; i < s.size(); ++i)
      v[i] = cti(s[i]);
    
    sort(v.begin(), v.end());
    print(v);
    while (next_permutation(v.begin(), v.end()))
      print(v);
  }
}