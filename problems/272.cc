#include <iostream>
using namespace std;
int main() {
  string s;
  bool open = false;
  while (getline(cin,s)) {
    size_t pos = s.find('"');
    while (pos != string::npos) {
      if (open) s.replace(pos, 1, "''");
      else  s.replace(pos, 1, "``");
      open = !open;
      pos = s.find('"', pos+1);
    }
    cout << s << endl;
  }
}