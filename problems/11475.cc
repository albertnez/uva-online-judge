#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> VI;

VI B;
string S, P;
void precalc() {
  B = VI(P.size()+1);
  B[0] = -1;
  int i = 0, j = -1;
  while (i < int(P.size())) {
    while (j != -1 and P[i] != P[j]) j = B[j];
    ++i;
    ++j;
    B[i] = j;
  }
}

int kmp() {
  int i = 0, j = 0;
  while (i < int(S.size())) {
    while (j != -1 and S[i] != P[j]) j = B[j];
    ++i;
    ++j;    
    if (i == int(S.size())) {
      return j; //get letters that matched. those are inside given palindrom
    }
  }
  return 0;
}

int main() {
  
  
  while (cin >> S) {
    P = "";
    for (int i = int(S.size())-1; i >= 0; --i) P += S[i];
    precalc();
    int n = kmp();
    cout << S + P.substr(n) << endl;
  }
}