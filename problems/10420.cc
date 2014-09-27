#include <iostream>
#include <map>
#include <sstream>
using namespace std;
int main() {
  int n;
  cin >> n;
  map<string,int> msi;
  cin.ignore();
  while (n--) {
    string s;
    getline(cin,s);
    istringstream ss(s);
    ss >> s;
    ++msi[s];
  }
  for (map<string,int>::const_iterator it = msi.begin(); it != msi.end(); ++it)
    cout << it->first << ' ' << it->second << endl;
}
