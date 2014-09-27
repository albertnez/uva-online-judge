#include <iostream>
#include <vector>
#include <cstdio>
#include <cstring>
using namespace std;

const int inf = 1e5;

char v[100][10];


int main() {
  ios_base::sync_with_stdio(false);
  int n; scanf("%d", &n);
  for (int i = 0; i < n; ++i)
    scanf("%s", v[i]);
  
  int m; scanf("%d", &m);
  
  while (m--) {
    int i; scanf("%d", &i);
    --i;
    
    if (strcmp(v[i],"?") != 0) printf("%s\n", v[i]);
    else {
      int indxl, indxr;
      int il = inf, ir = inf;
      
      int t = 0;
      while (i-t >= 0 and strcmp(v[i-t],"?") == 0) ++t;
      if (i-t >= 0) {
        il = t;
        indxl = i-t;
      }
      t = 0;
      while (i+t < n and strcmp(v[i+t],"?") == 0) ++t;
      if (i+t < n) {
        ir = t;
        indxr = i+t;
      }
      
            
      if (il == ir) printf("middle of %s and %s\n", v[indxl], v[indxr]);
      else if (il < ir) {
        for (int k = 0; k < il; ++k) printf("right of ");
        printf("%s\n", v[indxl]);
      }
      else {
        for (int k = 0; k < ir; ++k) printf("left of ");
        printf("%s\n", v[indxr]);
      }
    }
  } 
}