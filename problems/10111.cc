#include <iostream>
#include <cstring>
#include <vector>
using namespace std;

vector<vector<char> > map;
int N;
int posi[16];
int posj[16];
int exp[16];
int memo[2][550000];


int get(int n, int i) {
  return (n/exp[i])%3;
}

void set(int & n, int i, int x) {
  x = x-get(n, i);
  n += exp[i]*x;
}


bool finished(int state) {
  for (int i = 0; i < N; ++i)
    if (get(state, i) == 2) return false;
  return true;
}

// 2 none, 0 lose, 1 win
int check(int player, int state) {
  vector<vector<int> > m(4, vector<int>(4));
  
  for (int i = 0; i < 4; ++i) {
    for (int j = 0; j < 4; ++j) {
      int x = 0;
      if (map[i][j] == 'x') x = 1;
      else if (map[i][j] == '.') x = 2;
      m[i][j] = x;
    }
  }
  
  for (int i = 0; i < N; ++i) {
    m[posi[i]][posj[i]] = get(state, i);
  }
  
  //diagonals
  int x = m[0][0];
  bool valid = true;
  for (int i = 1; i < 4; ++i) valid &= (x == m[i][i]);
  if (valid and x != 2) return (x == player);
  
  x = m[0][3];
  valid = true;
  for (int i = 1; i < 4; ++i) valid &= (x == m[i][3-i]);
  if (valid and x != 2) return (x == player);
  
  //rows
  for (int i = 0; i < 4; ++i) {
    valid = true;
    x = m[i][0];
    for (int j = 0; j < 4; ++j) valid &= (x == m[i][j]);
    if (valid and x != 2) return (x == player);
  }
  
  //cols
  for (int j = 0; j < 4; ++j) {
    valid = true;
    x = m[0][j];
    for (int i = 0; i < 4; ++i) valid &= (x == m[i][j]);
    if (valid and x != 2) return (x == player);
  }
  
  return 2; // tie
}

// 0 lose, 1 win, 2 tie
pair<int,int> wins(bool player, int state) {
  int ch = check(player, state);
  if (ch != 2)
    return pair<int,int>(ch, -1);
  if (finished(state))
    return pair<int,int>(2, -1); //tie    
    
  int & ans = memo[player][state];
  
  if (ans != -1) return pair<int,int> (ans, -1);
  
  
  ans = 0;
  int ind = 0;
  for (int i = 0; i < N; ++i) {
    if (get(state, i) == 2) {
      int newstate = state;
      set(newstate, i, player);
      int x = wins(1-player, newstate).first;
      if (x == 0 and ans != 1) {
        ans = 1;
        ind = i;
      }
      else if (x == 2 and ans == 0) {
        ans = 2;
        ind = i;
      }
    }
  }
  return pair<int,int>(ans,ind);
}

int main() {
  exp[0] = 1;
  for (int i = 1; i < 16; ++i) exp[i] = exp[i-1]*3;
  
  char c;
  while (cin >> c and c == '?') {
    memset(memo, -1, sizeof memo);
    map = vector<vector<char> > (4, vector<char>(4));
    int ind = 0;
    for (int i = 0; i < 4; ++i) {
      for (int j = 0; j < 4; ++j) {
        cin >> map[i][j];
        if (map[i][j] == '.') {
          posi[ind] = i;
          posj[ind] = j;
          ++ind;
        }
      }
    }
    N = ind;
    
    
    int state = 0;
    for (int i = 0; i < N; ++i)
      set(state, i, 2);
    
    pair<int, int> ans =  wins(1, state);
    
    if (ans.first == 1) cout << "(" << posi[ans.second] << "," << posj[ans.second] << ")" << endl;
    else cout << "#####" << endl;
  }
  
}