#include <iostream>
#include <sstream>
using namespace std;

int main() {
  string s;
  while (getline(cin,s)) {
    istringstream ss(s);
    int sum = 0;
    int maxim = 0;
    int n;
    while (ss >> n) {
      sum = max(0, sum+n);
      maxim = max(maxim, sum);
    }
    cout << maxim << endl;
  }
}