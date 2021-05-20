#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

struct UnionFind {
  vector<int> par, siz;

  // initialize
  UnionFind(int n): par(n, -1), siz(n, 1) {}

  int root(int x){
    if (par[x] == -1) return x;
    else return par[x] = root(par[x]);
  }

  int issame(int x, int y){
    return root(x)==root(y);
  }

  bool unite(int x, int y){
    x = root(x);
    y = root(y);
    if (x == y) return false;
    if (siz[x] < siz[y]) swap(x, y);
    par[y] = x;
    siz[x] += siz[y];
    return true;
  }

  int size(int x){
    return siz[root(x)];
  }
};


signed main() {
  int N, M;
  cin >> N >> M;

  UnionFind uf(N+1);

  int a, b;
  rep(i, M){
    cin >> a >> b;
    uf.unite(a, b);
  }

  int result = 0;
  rep(i, N){
    result = max(result, uf.size(i+1));
  }

  cout << result << endl;
  return 0;
}
