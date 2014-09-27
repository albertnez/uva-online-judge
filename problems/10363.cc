#include <iostream>
#include <vector>
using namespace std;
typedef vector<char> Vc;
typedef vector<Vc> Mc;

bool d1, d2;
bool col[3], row[3];

bool win(const Mc &m, char c) {
  d1 = true, d2 = true;
  for (int i = 0; i < 3; ++i) {
    row[i] = true, col[i] = true;
    for (int j = 0; j < 3; ++j) {
      if (m[i][j] != c) row[i] = false;
      if (m[j][i] != c) col[i] = false;
    }
    if (m[i][i] != c) d1 = false;
    if (m[2-i][i] != c) d2 = false;
  }
  for (int i = 0; i < 3; ++i)
    if (row[i] or col[i]) return true;
  return (d1 or d2);
}

int main() {
  int T; cin >> T;
  while (T--) {
    Mc m(3, Vc(3));
    int x = 0, o = 0;
    for (int i = 0; i < 3; ++i)
      for (int j = 0; j < 3; ++j) {
        cin >> m[i][j];
        x += m[i][j] == 'X';
        o += m[i][j] == 'O';
      }
    
    bool sol = true;
    if (x < o or x > o+1 or (win(m, 'O') and win(m, 'X'))) sol = false;
    if ((x == o and win(m, 'X')) or (x == o+1 and win(m, 'O'))) sol = false;
    else {
      char c = 'O';
      if (win(m, 'X')) c = 'X';
      else win(m, 'O');
      
      int valid = d1+d2;
      for (int i = 0; i < 3; ++i)
        valid += row[i] + col[i];

      if (valid > 1) {
        int count = 0;
        for (int i = 0; i < 3; ++i)
          if (row[i]) ++count;
        if (count > 1) sol = false;
        count = 0;
        for (int i = 0; i < 3; ++i)
          if (col[i]) ++count;
        if (count > 1) sol = false;
        
        count = row[0] + col[0] + d1;
        
        if (count > 1) {
          m[0][0] = '.';
          if (win(m, c))
            sol = false;
          m[0][0] = c;
        }
        count = row[0] + col[2] + d2;
        if (count > 1) {
          m[0][2] = '.';
          if (win(m, c))
            sol = false;
          m[0][2] = c;
        }
        count = row[2] + col[0] + d2;
        if (count > 1) {
          m[2][0] = '.';
          if (win(m, c))
            sol = false;
          m[2][0] = c;
        }
        count = row[2] + col[2] + d1;
        if (count > 1) {
          m[2][2] = '.';
          if (win(m, c))
            sol = false;
          m[2][2] = c;
        }

        count = row[1] + col[1] + d1 + d2;
        if (count > 1) {
          m[1][1] = '.';
          if (win(m, c))
            sol = false;
          m[1][1] = c;
        }
      }

    }
    cout << (sol ? "yes" : "no") << endl;
  }
}