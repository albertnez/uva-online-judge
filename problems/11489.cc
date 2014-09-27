#include <iostream>
using namespace std;

int main() {
  int T;
  cin >> T;
  int ncase = 0;
  while (T--) {
    string s; cin >> s;
    int mod[3] = {0,0,0};
    int ind = 0;
    for (int i = 0; i < int(s.size()); ++i) {
      int x = (s[i]-'0')%3;
      ++mod[x]; 
      ind += x;
    }
    ind %= 3;
    
    char ans = 'T';
    if ((ind == 0 and (mod[0]&1)) or (ind and mod[ind] and !(mod[0]&1))) ans = 'S'; 
    cout << "Case " << ++ncase << ": " << ans << endl;
  }
}