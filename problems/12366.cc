#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef vector<int> Vi;



bool ispair(const Vi &a) {
  return ((a[0] == a[1] and a[1] != a[2]) or (a[0] != a[1] and a[1] == a[2]));
}

bool istriplet(const Vi &a) {
  return (a[0] == a[1] and a[1] == a[2]);
}

bool isnone(const Vi &a) {
  return (!ispair(a) and !istriplet(a));
}

int getp(const Vi &a) {
  if (a[0] == a[1]) return a[0];
  return a[2];
}

int getd(const Vi &a) {
  if (a[0] == a[1]) return a[2];
  return a[0];
}

bool win(const Vi &a, const Vi &b) {
  if (ispair(a) and isnone(b)) return true;
  if (istriplet(a) and !istriplet(b)) return true;
  if (ispair(a) and ispair(b)) {
    int pa = getp(a), pb = getp(b), da = getd(a), db = getd(b);
    if (pa > pb) return true;
    if (pa >= pb and da > db) return true;
    return false;
  }
  if (istriplet(a) and istriplet(b))
    if (a[0] > b[0]) return true;
  return false;
}

void printv(const Vi &v) {
  for (int i = 0; i < v.size(); ++i)
    cout << (i?" ":"") << v[i];
  cout << endl;
}

int main() {
  Vi a(3);
  while (cin >> a[0] >> a[1] >> a[2] and (a[0]|a[1]|a[2])) {
    sort(a.begin(), a.end());
    
    Vi b(3);
    bool finished = false;
    for (int i = 1; i <= 13; ++i) {
      for (int j = 1; j <= 13; ++j) if (i != j) {
        b[0] = j;
        b[1] = b[2] = i;
        if (b[0] > b[2]) swap(b[2], b[0]);
        
        if (win(b,a) and !finished) {
          printv(b);
          finished = true;
        }
      }
    }
    
    //triplets
    for (int i = 1; i <= 13; ++i) {
      b[0] = b[1] = b[2] = i;
      if (win(b, a) and !finished) {
        printv(b);
        finished = true;
      }
    }
    if (!finished) cout << "*" << endl;
  }
}