#include <iostream>
using namespace std;

struct Qtree{
  bool x;
  Qtree *p[4];
  Qtree(bool xx) {
    x = xx;
    for (int i = 0; i < 4; ++i)
      p[i] = NULL;
  }
};

bool full(Qtree *p) {
  for (int i = 0; i < 4; ++i)
    if (p->p[i] != NULL) return false;
  return true;
}

void init(Qtree * p) {
  for (int i = 0; i < 4; ++i) {
    char c;
    cin >> c;
    if (c == 'p') {
      p->p[i] = new Qtree(false);
      init(p->p[i]);
    }
    else {
      p->p[i] = new Qtree(c == 'f');
    }
  }
}

void del(Qtree * p) {
  if (p == NULL) return;
  for (int i = 0; i < 4; ++i)
    del(p->p[i]);  
  delete p;
}

void sum(Qtree * &a, Qtree * &b) {
  if (full(a) and full(b)) { // if both leaves, merge
    a->x |= b->x;
  }
  else if (!full(a) and !full(b)) { // both parents
    for (int i = 0; i < 4; ++i)
      sum(a->p[i], b->p[i]);
  }
  else if (full(a)) { // if only A is full
    if (a->x) return; // already filled
    del(a);
    a = b;  // A is empty, assign it to B
    b = NULL;

  }
  else { // only B is full
    if (b->x) { // B filled
      del(a);
      a = b;      
      b = NULL;
    }
  }
}

int count(Qtree *p, int depth) {
  if (full(p)) return (p->x ? 1*depth : 0);
  int n = 0;
  for (int i = 0; i < 4; ++i)
    n += count(p->p[i], depth/4);
  return n;
}

int initDepth = 4*4*4*4*4;

int main () {
  int T; cin >> T;
  while (T--) {
    Qtree *a = new Qtree(false), *b = new Qtree(false);
    char c;
    
    cin >> c;
    
    if (c == 'p') init(a);
    else a->x = (c == 'f');
    
    cin >> c;
    if (c == 'p') init(b);
    else b->x = (c == 'f');
        
    sum(a, b);
    
    cout << "There are " << count(a, initDepth) << " black pixels." << endl; 
    del(a);
    del(b);
  }
}
