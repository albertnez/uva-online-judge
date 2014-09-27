#include <iostream>
#include <set>
#include <algorithm>
#include <vector>
using namespace std;

string s;
int n;
vector<int> maxr;
vector<int> rep;
void debug() {
  cout << "s: " << s << endl;
  cout << "maxr = [";
  for (int i = 0; i < int(maxr.size()); ++i) cout << ", " << maxr[i];
  cout << "]" << endl;
  cout << "rep = [";
  for (int i = 0; i < int(rep.size()); ++i) cout << ", " << rep[i];
  cout << "]" << endl;
}

void precalc() {
  maxr.clear();
  rep.clear();
  string ns = "";
  sort(s.begin(), s.end());
  char old = '.';
  int irep = -1;
  for (int i = 0; i < int(s.size()); ++i) {
    if (s[i] != old) {
      old = s[i];
      ns += s[i];
      maxr.push_back(0);
      irep++;
    }
    ++maxr[irep];
  }
  s = ns;
  rep.assign(irep+1, 0);
  int t = 0;
  irep = 0;
  while (t < n) {
    if (rep[irep] == maxr[irep]) ++irep;
    ++rep[irep];
    ++t;
  }
}

bool incr() {
  int t = 0;
  int i = rep.size()-1;
  
  bool done = false;
  while (i-1 >= 0 and !done) {
    if (rep[i-1] and rep[i]+1 <= maxr[i]) {
      --rep[i-1];
      ++rep[i];
      done = true;
    }
    else {
      t += rep[i];
      rep[i] = 0;
      --i;
    }
  }
  
  if (!done) return false;
  
  while (t and i < int(rep.size())) {
    int p = min(maxr[i]-rep[i], t);
    t -= p;
    rep[i] += p;
    ++i;
  }
  return true;
}

void print() {
  for (int i = 0; i < int(rep.size()); ++i)
    for (int j = 0; j < rep[i]; ++j)
      cout << s[i];
  cout << endl;
}


int main() {
  while (cin >> s >> n) {
    precalc();

    do { 
      print();
    } while(incr());
  }
}