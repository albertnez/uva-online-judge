#include <iostream>
#include <vector>
using namespace std;

vector<int> B;
string P, T;
int count;

void precalc() {
  int i = 0, j = -1;
  B[0] = j;
  while (i < P.size()) {
    while (j >= 0 and P[i] != P[j]) j = B[j];
    ++i; ++j;
    B[i] = j;
  }
}

void match() {
  int i = 0, j = 0;
  while (i < T.size()) {
    while (j >= 0 and T[i] != P[j]) j = B[j];
    ++i; ++j;
    if (j == P.size()) {
      ++count;
      j = B[j];
    }
  }
}

int main() {
  while (cin >> P and P != ".") {
    B.assign(P.size()+1, 0);
    count = 0;
    T = P+P;
    precalc();
    match();
    cout << count-1 << endl;
  }
}