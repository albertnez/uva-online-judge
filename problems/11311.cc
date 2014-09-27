#include <iostream>
using namespace std;

int main() {
  int T; cin >> T;
  while (T--) {
    int m, n, r, c;
    cin >> m >> n >> r >> c;
    
    if ((r)^(m-r-1)^(c)^(n-c-1)) cout << "Gretel" << endl;
    else cout << "Hansel" << endl;   
  }
}