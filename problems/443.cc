#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
ll maxn = 2000000000LL;
int nume = 5843;
const string suff[4] = {"th", "st", "nd", "rd"};
int main() {
  vector<int> v(1, 0);
  for (ll a = 1; a <= maxn; a *= 2LL)
    for (ll b = a; b <= maxn; b *= 3LL)
      for (ll c = b; c <= maxn; c *= 5LL)
        for (ll d = c; d <= maxn; d *= 7LL)
          v.push_back(d);
   
  sort(v.begin(), v.end());
  int n;
  while (cin >> n and n) {
    string suf = suff[0];
    int m = n%10;
    int q = n%100;
    if (m >= 1 and m <= 3 and (q < 11 or q > 13)) suf = suff[m];
    cout << "The " << n << suf << " humble number is " << v[n] << "." << endl;
  }
}
