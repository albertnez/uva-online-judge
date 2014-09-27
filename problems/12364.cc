#include <iostream>
#include <vector>
using namespace std;
	      //0  1  2  3  4  5  6  7  8  9 10 11 12 13 14 15
int arr[16] = {-1, 1,-1, 3,-1, 2, 9, 6,-1, 5,-1, 4,-1, 8, 0, 7};

string up[10] = {".*", "*.", "*.", "**", "**", "*.", "**", "**", "*.", ".*"};
string mid[10] = {"**", "..", "*.", "..", ".*", ".*", "*.", "**", "**", "*."};
string down = "..";

int main() {
  int n;
  while (cin >> n and n) {
    char c; cin >> c;
    if (c == 'S') {
      vector<int> v(n);
      for (int i = 0; i < n; ++i) {
	char k; cin >> k;
	v[i] = k-'0';
      }
      for (int i = 0; i < 3; ++i) {
	for (int j = 0; j < n; ++j) {
	  if (i == 0) cout << (j?" ":"") << up[v[j]];
	  else if (i == 1) cout << (j?" ":"") << mid[v[j]];
	  else cout << (j?" ":"") << down;
	}
	cout << endl;
      }
    }
    else {
      vector<int> v(n, 0);
      for (int i = 0; i < 2; ++i) {
	for (int j = 0; j < n; ++j) {
	  char k; cin >> k;
	  if (k == '*') v[j] += (1 << (2*i));
	  cin >> k;
	  if (k == '*') v[j] += (1 << ((2*i)+1));
	  cin.ignore();
	}
      }
      string omit;
      getline(cin, omit);
      for (int i = 0; i < n; ++i) cout << arr[v[i]];
      cout << endl;      
    }
  }
}