#include <iostream>
#include <vector>
#include <iomanip>
using namespace std;

int weight(int n) {
  int t = 0;
  while (n) {
    if (n&1) t += 500;
    else t += 250;
    n >>= 1;
  }
  return t;
} 

string getstring(const string &s, int i) {
  string a = "";
  while (s[i] >= 'A' and s[i] <= 'Z')
    a += s[i++];
  return a;
}

void print0(const string &l, const string &r) {
cout << "........||........" << endl; 
cout << ".../\\...||.../\\..." << endl; 
cout << "../..\\..||../..\\.." << endl; 
cout << "./....\\.||./....\\." << endl; 
cout << "/" << setw(6) << setfill('.') << left << l << "\\||/" << setw(6) << setfill('.') << left << r << "\\" << endl; 
cout << "\\______/||\\______/" << endl; 
cout << "........||........" << endl; 
}
void print1(const string &l, const string &r) {
cout << "........||.../\\..." << endl;
cout << "........||../..\\.." << endl;
cout << ".../\\...||./....\\." << endl;
cout << "../..\\..||/" << setw(6) << setfill('.') << left << r << "\\" << endl;
cout << "./....\\.||\\______/" << endl;
cout << "/" << setw(6) << setfill('.') << left << l << "\\||........" << endl;
cout << "\\______/||........" << endl;
}
void print2(const string &l, const string &r) {
  cout << ".../\\...||........" << endl;
cout << "../..\\..||........" << endl;
cout << "./....\\.||.../\\..." << endl;
cout << "/" << setw(6) << setfill('.') << left << l << "\\||../..\\.." << endl;
cout << "\\______/||./....\\." << endl;
cout << "........||/" << setw(6) << setfill('.') << left << r << "\\" << endl;
cout << "........||\\______/" << endl;
}

int main() {
  int T; cin >> T;
  int ncase = 0;
  string line;
  getline(cin, line);
  
  while (T--) {
    string line;
    getline(cin, line);
    getline(cin, line);
    getline(cin, line);
    getline(cin, line);

    int state;
    /*  - 0
     *  / 1
     *  \ 2
     */
    string l, r;
    if (line[0] == '/') {
      state = 2;
      l = getstring(line, 1);
      getline(cin, line);
      getline(cin, line);
      r = getstring(line, 11);
      getline(cin, line);getline(cin, line);
    }
    else if (line[10] == '/') {
      state = 1;
      r = getstring(line, 11);
      getline(cin, line);
      getline(cin, line);
      l = getstring(line, 1);
      getline(cin, line);getline(cin, line);
    }
    else {
      state = 0;
      getline(cin, line);
      l = getstring(line, 1), r = getstring(line, 11);
      getline(cin, line);getline(cin, line);getline(cin, line);
    }
    
    
    int lw = 0, rw = 0;
    for (int i = 0; i < l.size(); ++i)
      lw += weight(l[i]);
    for (int i = 0; i < r.size(); ++i)
      rw += weight(r[i]);
    
    cout << "Case " << ++ncase << ":" << endl;
    
    if (state == 0 and lw == rw) cout << "The figure is correct." << endl;
    else if (state == 1 and lw > rw) cout << "The figure is correct." << endl;
    else if (state == 2 and lw < rw) cout << "The figure is correct." << endl;
    else if (lw == rw) print0(l, r);
    else if (lw > rw) print1(l, r);
    else print2(l, r);

    
  }
}