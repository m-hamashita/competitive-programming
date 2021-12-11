#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

struct UnionFind {
    vector<int> par, siz;

    // initialize
    UnionFind(int n) : par(n, -1), siz(n, 1) {
    }

    int root(int x) {
        if (par[x] == -1)
            return x;
        else
            return par[x] = root(par[x]);
    }

    int issame(int x, int y) {
        return root(x) == root(y);
    }

    bool unite(int x, int y) {
        x = root(x);
        y = root(y);
        if (x == y)
            return false;
        if (siz[x] < siz[y])
            swap(x, y);
        par[y] = x;
        siz[x] += siz[y];
        return true;
    }

    int size(int x) {
        return siz[root(x)];
    }
};

signed main() {
    ll N, M;
    cin >> N >> M;
    vector<vector<int>> v(N);
    int a, b;
    UnionFind uf(N);
    rep(i, M) {
        cin >> a >> b;
        v[a - 1].push_back(b - 1);
        v[b - 1].push_back(a - 1);
        // 閉路あり
        if (uf.issame(a - 1, b - 1)) {
            cout << "No" << endl;
            return 0;
        }
        uf.unite(a - 1, b - 1);
    }
    rep(i, N) {
        if (v[i].size() > 2) {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;

    return 0;
}
