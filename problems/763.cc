#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef __int128 ll;
typedef vector<ll> Vll;
const int maxn = 110;

Vll fib(maxn);

ll tofib(const string & s) {
  ll ans = 0;
  for (int i = 0; i < int(s.size()); ++i) {
    if (s[s.size()-1-i] == '1')
      ans += fib[i];
  }
  return ans;
}

string decompose(ll n) {
  bool firstone = true;
  string ans = "";
  for (int i = maxn-1; i >= 0; --i) {
    if (n >= fib[i]) {
      firstone = false;
      n -= fib[i];
      ans += "1";
    }
    else if (!firstone) {
      ans += "0";
    }
  }
  if (ans == "") ans = "0";
  return ans;
}

void print(ll n) {
  string s = "";
  while (n) {
    s += '0' + (n%10);
    n /= 10;
  }
  reverse(s.begin(), s.end());
  cout << s << endl;
}

int main() {
  fib[0] = 1;
  fib[1] = 2;
  for (int i = 2; i < maxn; ++i) {
    fib[i] = fib[i-1] + fib[i-2];
  }
  
  string a, b;
  bool first = true;
  while (cin >> a >> b) {
    if (first) first = false;
    else cout << endl;
    
    cout << decompose(tofib(a)+tofib(b)) << endl;
  }
}