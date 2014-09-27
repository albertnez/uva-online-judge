#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>
using namespace std;

typedef pair<string,string> PSS;
typedef vector<PSS> VPSS;
#define X first
#define Y second

const int maxl = 2050;
const int maxn = 150;

VPSS v;
int length;

bool match(const string &a, const string &b, const string &c) {
  return (a+b == c or b+a == c);
}

bool f(int i, const string &s) {
  int j = length-i;
  string a = v[i].X;
  string b = v[j].X;
  string c = v[i].Y;
  string d = v[j].Y;
  if (a == "") return true;
  if (c == "" and d == "") return match(a,b,s);
  if (c == "") return (match(a,b,s) and match(a,d,s));
  if (d == "") return (match(a,b,s) and match(c,b,s));
  return ((match(a,b,s) and match(c,d,s)) or (match(a,d,s) and match(c,b,s)));
}

bool check(const string &s) {
  int i = 0;
  bool pos = true;
  while (pos and i < length) {
    pos = f(i, s);
    ++i;
  }
  return pos;
}

int main() {
  bool first = true;
  int T; cin >> T;
  string line;
  getline(cin,line);
  getline(cin,line);
  while (T--) {
    int sum = 0, numdif = 0;
    v = VPSS(maxl);
    int least = 1e9;
    while (getline(cin,line) and line != "") {
      int l = line.size();
      least = min(least, l);
      if (v[l].X == "") {
        ++numdif;
        v[l].X = line;
        sum += l;
      }
      else if (v[l].X != line and v[l].Y == "") {
        ++numdif;
        v[l].Y = line;
        sum += l;
      }
    }
    
    length = 2* sum / numdif;
    /*
    if (numdif <= 2) {
      cout << v[least].X << v[length-least].X << endl;
    }
    else {
      
    }
    */
    int i1 = least;
    int i2 = length-least;
    string s = v[i1].X+v[i2].X;
    bool win = check(s);
    if (!win) {
      s = v[i2].X+v[i1].X;
      win = check(s);
    }
    if (!win) {
      s = v[i1].X +v[i2].Y;
      win = check(s);
    }
    if (!win) {
      s = v[i2].Y +v[i1].X;
      win = check(s);
    }
    if (!win) {
      s = v[i1].Y +v[i2].X;
      win = check(s);
    }
    if (!win) {
      s = v[i2].X +v[i1].Y;
      win = check(s);
    }
    if (!win) {
      s = v[i1].Y + v[i2].Y;
      win = check(s);
    }
    if (!win) {
      s = v[i2].Y + v[i1].Y;
      win = check(s);
    }
    
    if (first) first = false;
    else cout << endl;
    cout << s << endl;
    //cout << "length: " << length << endl;
  }
}