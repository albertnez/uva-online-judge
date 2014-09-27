#include <iostream>
#include <vector>
#include <map>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;








int main() {
  int T; cin >> T;
  while (T--) {
    int n, b; cin >> n >> b;
    MI prices, quality;
    VI taken;
    map<string,int> ids;
    int types = 0;
    for (int i = 0; i < n; ++i) {
      string type, name;
      int p, q;
      cin >> type >> name >> p >> q;
      if (ids.find(type)==ids.end()) {
        prices.push_back(VI());
        quality.push_back(VI());
        ids[type] = types++;
      }
      prices[ids[type]].push_back(p);
      quality[ids[type]].push_back(q);
    }
    
    taken = VI(types);
    
    for (int i = 0; i < types; ++i) {
      int minp = 1e9+1;
      int ind = 0;
      for (int j = 0; j < int(prices[i].size()); ++j) {
        if (prices[i][j] < minp) {
          minp = prices[i][j];
          ind = j;
        }
      }
      taken[i] = ind;
      b -= prices[i][ind];
    }
    
    
    bool change = true;
    int minq;
    while (change) {
      change = false;
      //find minimum quality
      minq = 1e9+10;
      int nummin = 0;
      for (int i = 0; i < types; ++i)
        if (quality[i][taken[i]] == minq) ++nummin;
        else if (quality[i][taken[i]] < minq) {
          minq = quality[i][taken[i]];
          nummin = 1;
        }
      
      
      for (int i = 0; i < types; ++i) if (quality[i][taken[i]] == minq) {
        int newtaken = -1;
        int bestp = 1e9+10;
        for (int j = 0; j < int(prices[i].size()); ++j) {
          if (quality[i][j] > minq and prices[i][j] < bestp) {
            bestp = prices[i][j];
            newtaken = j;
          }
        }
        
        
        if (newtaken >= 0 and prices[i][newtaken]-prices[i][taken[i]] <= b) {
          b -= prices[i][newtaken]-prices[i][taken[i]];
          taken[i] = newtaken;
          --nummin;
        }
      }
      change = !nummin;
    }
    cout << minq << endl;
  }
}