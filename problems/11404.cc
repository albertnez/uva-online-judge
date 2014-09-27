#include <iostream>
#include <string>
#include <cstring>
using namespace std;
typedef pair<int,char> PIC;

int ncase = 0;
const int maxn = 1001;

string s;

int memo[maxn][maxn]; 

int pre(int i, int j) {
  if (i == j) return memo[i][j] = 1;
  if (i+1 == j) return memo[i][j] = (s[i] == s[j] ? 2 : 1);
  if (memo[i][j] != -1) return memo[i][j];
  
  int &ans = memo[i][j] = 0;
  
  if (s[i] == s[j]) return ans = 2 + pre(i+1, j-1);
  return ans = max(pre(i+1, j), pre(i, j-1));
}


void print(int i, int j) {
  
  if (i == j) {
    cout << s[i];
    return;
  }
  if (i+1 == j) {
    if (s[i] == s[j]) cout << s[i] << s[j];
    else cout << (s[i] < s[j] ? s[i] : s[j]);
    return;
  }
  
  
  int maxv = -1;
  char bestc = 'z';
  int bs = -1, be = -1;
  for (int k = 0; k < 26; ++k) {
    char c = 'a'+k;
    
    size_t sp = s.find_first_of(c, i);
    size_t ep = s.find_last_of(c, j);
    
    if (sp != string::npos and ep != string::npos and sp != ep) {
      int tmp = memo[sp][ep];
      if (tmp > maxv) {
        bs = sp;
        be = ep;
        maxv = tmp;
        bestc = c;
      }
    }
    else if (sp != string::npos and ep != string::npos and be == -1 and c <= bestc) {
      bs = sp;
      bestc = c;      
    }
  }
  
  if (bs >= 0 and be >= 0) {
    cout << bestc;
    print(bs+1, be-1);
    cout << bestc;
  }
  else if (bs >= 0) {
    cout << bestc;
  }
}

int main() {
  ios_base::sync_with_stdio(false);
  
  while (cin >> s) {
    memset(memo, -1, sizeof memo);
    pre(0, s.size()-1);  
    print(0, s.size()-1);
    cout  << endl;
  }
  
  
}