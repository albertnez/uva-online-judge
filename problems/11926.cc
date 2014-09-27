#include <iostream>
using namespace std;

int main() {
  int n, m, a, b, f;
  while (cin >> n >> m and (n != 0 or m != 0)) {
    bool t[1000001] = {false};
    bool conflict = false;
    
    for (int i = 0; i < n; ++i){
      cin >> a >> b;
      while (a < b and !conflict) {
        if (t[a] == true)
          conflict = true;
        t[a] = true;
        ++a;
        
      }   
    }


    //repetitions
  for (int i = 0; i < m; ++i) {
      cin >> a >> b >> f;
      while (a < b and !conflict) {
        int k = a;
        while (k < 1000001 and !conflict) {
          if (t[k] == true)
            conflict = true;
          t[k] = true;
          k += f;
        }  
        ++a;
      }  
    } 
  if (!conflict) cout << "NO ";
  cout << "CONFLICT" << endl;
  }  
}
