#include <iostream>
using namespace std;

const int dif[6] = {0, -1, 0, 0, 0, 0};
const int di[6] = {1, 1, 0, -1, -1, 0};
const int dj[6] = {0, -1, -1, 0, 1, 1};

int main() {
  int n;
  while (cin >> n) {
    int t = 1;
    int step = 1;
    int pi = 0, pj = 0;
    while (t < n) {
      for (int i = 0; i < 6 and t < n; ++i) {
        int d = step+dif[i];
        if (t+d > n) d = n-t;
        pi += di[i]*d;
        pj += dj[i]*d;
        t += d;
      }
      ++step;
    }
    cout << pj << " " << pi << endl;
  }
}