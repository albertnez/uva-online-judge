#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef vector<int> VI;
typedef vector<VI> MI;

int N, M, P, source, sink;
MI G, res;
int ptoi(int r, int c) { return (r*M + c)*2; }

const int infflow = 1000;
const int di[4] = {1, -1, 0, 0};
const int dj[4] = {0, 0, 1, -1};

int main() {
  while (cin >> N >> M >> P) {
    int size = N*M*2+2;
    source = size-2;
    sink = size-1;
    // verts -> in = i, out = i+1
    // source = size-2, sink = size-1
    G = MI(size);
    res = MI(size, VI(size, 0));
    
    for (int i = 0; i < N; ++i) {
      for (int j = 0; j < M; ++j) {
        char c; cin >> c;
        int vtx = ptoi(i, j);
        
        if (c != '~') {
          G[vtx].push_back(vtx+1);
          G[vtx+1].push_back(vtx);
        }
        if (c == '*' or c == '.') res[vtx][vtx+1] = 1;          
        else if (c == '#' or c == '@') res[vtx][vtx+1] = infflow;
        
        // add neighbours
        for (int k = 0; k < 4; ++k) {
          int ni = i+di[k], nj = j+dj[k];
          if (ni >= 0 and ni < N and nj >= 0 and nj < M) {
            int nvtx = ptoi(ni, nj);
            G[vtx+1].push_back(nvtx);
            G[nvtx].push_back(vtx+1);
            res[vtx+1][nvtx] = infflow;
          }
        }
        if (c == '*') { // source
          G[source].push_back(vtx);
          G[vtx].push_back(source);
          res[source][vtx] = 1;
        }
        else if (c == '#') { //sink
          G[vtx+1].push_back(sink);
          G[sink].push_back(vtx+1);
          res[vtx+1][sink] = P;
        }
      }
    }
    
    bool augmentingPath = true;
    int maxflow = 0;
    while (augmentingPath) {
      queue<int> q;
      vector<bool> visited(size, false);
      visited[source] = true;
      q.push(source);
      vector<int> from(size, -1);
      
      bool found = false;
      while (!q.empty()) {
        int u = q.front(); q.pop();
        if (u == sink) {
          found = true;
          break;
        }
        for (int i = 0; i < int(G[u].size()); ++i) {
          int v = G[u][i];
          if (!visited[v] and res[u][v] > 0) {
            from[v] = u;
            visited[v] = true;
            q.push(v);
          }
        }
      }
      int qtt = 0;
      if (found) {
        int flow = 1e9;
        int u = sink;
        while (from[u] != -1) {
          flow = min(flow, res[from[u]][u]);
          u = from[u];
        }
        qtt = flow;
        u = sink;
        while (from[u] != -1) {
          res[from[u]][u] -= flow;
          res[u][from[u]] += flow;
          u = from[u];
        }
      }
      augmentingPath = qtt;
      maxflow += qtt;
    }
    cout << maxflow << endl;
  }
}