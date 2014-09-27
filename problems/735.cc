#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> Vi;
int main() {
  Vi v;
  vector<bool> used(70, false);
  v.push_back(50);
  used[50] = true;
  for (int i = 0; i <= 20; ++i)
    for (int j = 1; j <= 3; ++j)
      if (!used[i*j]) { used[i*j] = true; v.push_back(i*j); }
  int n = v.size();
  int num;
  while (cin >> num and num > 0) {
    int count = 0, perm = 0;
    for (int i = 0; i < n; ++i) for (int j = i; j < n; ++j) for (int k = j; k < n; ++k) {
      if (num-v[i]-v[j]-v[k] == 0) {
	++count;
	if (i == j and j == k) ++perm;
	else if (i == j or j == k or k == i) perm += 3;
	else perm += 6;
      }
    }
    if (!count) cout << "THE SCORE OF " << num << " CANNOT BE MADE WITH THREE DARTS." << endl;
    else {
      cout << "NUMBER OF COMBINATIONS THAT SCORES " << num << " IS " << count << "." << endl;
      cout << "NUMBER OF PERMUTATIONS THAT SCORES " << num << " IS " << perm << "." << endl;
    }
    cout << "**********************************************************************" << endl;
  }
  cout << "END OF OUTPUT" << endl;
}