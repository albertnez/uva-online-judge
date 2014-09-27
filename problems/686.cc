#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef vector<int> VI;

const int maxn = (1<<15)+5;

int main() {
  VI primes, aux;
  vector<bool> isprime(maxn, true);
  
  for (int i = 2; i < maxn; ++i) {
    if (isprime[i]) {
      primes.push_back(i);
      if (i*i <= maxn) {
        for (int j = i*i; j < maxn; j += i)
          isprime[j] = false;
      }
    }
  }  
  int n;
  while (cin >> n and n) {
    int sum = 0;
    int i = 0;
    while (i < int(primes.size()) and primes[i]*2 <= n) {
      if (isprime[n-primes[i]]) ++sum;
      ++i;
    }
    cout << sum << endl;
  }
  
}