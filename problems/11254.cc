#include <iostream>
#include <cmath>
using namespace std;
typedef long long ll;
int main() {
  int n;
  while (cin >> n and n != -1) {
    int maxit = (sqrt(8LL*ll(n)+1)-1)/2;
    
    int ans = -1;
    int a = -1;
    for (int i = maxit; ans == -1 and i >= 1; --i) {
      a = (2*n - i*i + i)/(2*i);
      if ((i*(a+a+i-1))/2 == n)
        ans = i;
    }
    
    cout << n << " = " << a << " + ... + " << a+ans-1 << endl;   
  }
}