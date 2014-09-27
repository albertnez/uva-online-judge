#include <iostream>
#include <vector>
using namespace std;

bool leap(int n) { return (n%400 == 0 or (n%100 != 0 and n%4 == 0)); }

int nextm4(int n) {
  while (n%4) ++n;
  return n;
}

int nextc(int n) {
  if (n%100 == 0) return n;
  return (n/100+1)*100;
}

int nextm400(int n) {
  if (n%400 == 0) return n;
  n = (n/100+1)*100;
  while (n%400) n+= 100;
  return n;
}

int main() {
  int T; cin >> T;
  int ncase = 0;
  while (T--) {
    string sm, sd, em, ed;
    int sy, ey;
    cin >> sm >> sd >> sy >> em >> ed >> ey;
    
    if (sm != "January" and sm != "February") ++sy;
    if (em != "January" and (em != "February" or (em == "February" and ed == "29,"))) ++ey;
    
    sy = nextm4(sy);
    ey = nextm4(ey);
    int sc = nextc(sy), ec = nextc(ey);
    int sm400 = nextm400(sy), em400 = nextm400(ey);
    
    int ans = (ey-sy)/4;
    ans -= (ec-sc)/100;
    ans += (em400-sm400)/400;    
    
//     cout << "sy: " << sy << " ey: " << ey << endl;
    cout << "Case " << ++ncase << ": " << ans << endl;
  }
}