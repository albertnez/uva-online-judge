#include <iostream>
#include <cmath>
using namespace std;

int main() {
  cout.precision(3);
  cout.setf(ios::fixed);
  
  int T; cin >> T;
  while (T--) {
    int n;
    cin >> n;
    
    int m = max(0,n-2);
    int q = max(0,n-3);
    
    int l = (m*(m+1))/2;
    int r = (q*(q+1))/2;
    
    double total = 2*(n-1) + 2*(n>1) + (n>2) + (l+r)*sqrt(2) + m + q;
    cout << total << endl;
    if (T) cout << endl;
  }
}