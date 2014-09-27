#include <iostream>
#include <cmath>
using namespace std;
int main() {
  int n, k;
  char c;
  cin >> n;
  for (int i = 0; i < n; ++i) {
    int suml = 0;
    cin >> c;
    suml += (c - 'A')*26*26;
    cin >> c;
    suml += (c - 'A')*26;
    cin >> c;
    suml += (c - 'A');
    cin >> c;
    cin >> k;
    if (abs(suml - k) > 100)
      cout << "not ";
    cout << "nice" << endl;
  }
}

