#include <iostream>
#include <vector>
using namespace std;
int N, M, ind, Z;
string rule;
vector<string> vs;
vector<int> vi;

void bt(int n) {
  if (n == Z) {
    int in = 0;
    for (int i = 0; i < rule.size(); ++i) {
      if (rule[i] == '#') cout << vs[ind];
      else cout << vi[in++];
    }
    cout << endl;
  }
  else {
    for (int i = 0; i < 10; ++i) {
      vi[n] = i;
      bt(n+1);
    }
  }  
}

int main() {
  while (cin >> N) {
    cout << "--" << endl;
    vs = vector<string> (N);
    for (int i = 0; i < N; ++i)
      cin >> vs[i];
    cin >> M;
    for (int i = 0; i < M; ++i) {
      cin >> rule;
      Z = 0;
      for (int j = 0; j < rule.size(); ++j)
        if (rule[j] == '0') ++Z;
      vi = vector<int> (Z, 0);
      
      for (int j = 0; j < N; ++j){
        ind = j;
        bt(0);
      }    
    }  
  }
}