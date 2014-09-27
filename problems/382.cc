#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;
typedef vector<int> Vi;

const int maxn = 60001;

int main() {
  Vi sum(maxn, 1);
  sum[1] = 0;
  for (int i = 2; i <= maxn/2; ++i) {
    for (int j = i*2; j < maxn; j+=i) {
      sum[j] += i;
    }
  }
  
  cout << "PERFECTION OUTPUT" << endl;
  int n;
  while (cin >> n and n) {
    cout << setfill(' ') << setw(5) << n;
    cout << "  ";
    if (sum[n] < n) cout << "DEFICIENT" << endl;
    else if (sum[n] > n) cout << "ABUNDANT" << endl;
    else cout << "PERFECT" << endl;
  }
  cout << "END OF OUTPUT" << endl;
}