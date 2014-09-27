#include <iostream>
using namespace std;

int main() {
  int n;
  cin >> n;
  string one = "one";
  while (n--) {
    string s;
    cin >> s;
    if (s.size() == 5) cout << 3 << endl;
    else {
      int m = 0;
      for (int i = 0; i < 3; ++i)
        m += s[i] != one[i];
      if (m <= 1) cout << 1 << endl;
      else cout << 2 << endl;
    }
  }
}