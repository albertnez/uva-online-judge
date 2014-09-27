#include <iostream>
#include <vector>
#include <iomanip>
#include <algorithm>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;

const int inf = 1e9;

const int VISITED = 2;
const int UNVISITED = 0;
const int EXPLORED = 1;

MI G;
MI sign;
VI value;
VI state;
VI cycle;
vector<string> expression;
vector<bool> valid;
int n, m;

bool isNum(const string & s) {
  return (s[0] >= '0' and s[0] <= '9');
}

int stoi(const string & s) {
  int n = 0;
  for (int i = 0; i < int(s.size()); ++i) {
    n *= 10;
    n += s[i]-'0';
  }
  return n;
}

string itos(int cell) {
  string s;
  s += ('A'+cell/m);
  s += ('0'+cell%m);
  return s;
}

int stoc(const string & s) {
  return (s[0]-'A')*m + s[1]-'0';
}

void process(int cell) {
  int tmp = 0;
  int op = 1;
  string line;
  cin >> line;
  expression[cell] = line;
  size_t pos = 0;
  if (line[0] == '-') {
    op = -1;
    pos = 1;
  } 
  size_t len = line.find_first_of("+-", pos);
  while (len != string::npos) {
    string subs = line.substr(pos, len-pos);
    if (isNum(subs)) tmp += stoi(subs)*op;
    else {
      G[cell].push_back(stoc(subs));
      sign[cell].push_back(op);
      valid[cell] = false;
    }
    
    if (line.substr(len, 1) == "+") op = 1;
    else op = -1;
    pos = len+1;
    len = line.find_first_of("+-", pos);
  }
  string subs = line.substr(pos);
  if (isNum(subs)) tmp += stoi(subs)*op;
  else {
    G[cell].push_back(stoc(subs));
    sign[cell].push_back(op);
    valid[cell] = false;
  }
  value[cell] = tmp;
}

bool dfs(int u) {
  if (state[u] == VISITED) return true;
  if (state[u] == EXPLORED) return false;
  state[u] = EXPLORED;
  
  for (int i = 0; i < int(G[u].size()); ++i) {
    int v = G[u][i];
    if (dfs(v)) value[u] += value[v]*sign[u][i];
    else {
      cycle.push_back(u);
      return false;
    }
  }
  state[u] = VISITED;
  return true;
}

int main() {
  while (cin >> n >> m and (n|m)) {
    int ncells = n*m;
    G = MI(ncells);
    sign = MI(ncells);
    cycle.clear();
    
    value.assign(ncells, 0);
    valid.assign(ncells, true);
    expression.assign(ncells, "");
    state.assign(ncells, UNVISITED);

    for (int i = 0; i < ncells; ++i) {
      process(i);
    }
    
    bool possible = true;
    
    for (int i = 0; i < ncells; ++i) {
      if (state[i] == UNVISITED) 
        if (!dfs(i)) {
          possible = false;
        }
    }
    
    
    if (!possible) {
      sort(cycle.begin(), cycle.end());
      for (int i = 0; i < int(cycle.size()); ++i) {
        cout << itos(cycle[i]) << ": " << expression[cycle[i]] << endl;
      }
    }
    else {
      cout << "      0";
      for (int i = 0; i < m-1; ++i) cout << setw(6) << char('0' + i + 1);
      
      for (int i = 0; i < ncells; ++i) {
        if (i%m == 0) cout << endl << char('A'+(i/m));
        cout << setw(6) << value[i];
      }
      cout << endl;
    }
    cout << endl;
  }
}