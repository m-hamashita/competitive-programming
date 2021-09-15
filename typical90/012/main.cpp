#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

// UnionFind Tree
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
    ll H, W, Q;
    cin >> H >> W >> Q;
    ll t;
    ll r1, c1, r2, c2;
    ll square[H][W];
    rep(i, H) rep(j, W) square[i][j] = 0;
    UnionFind uf(H * W);

    rep(i, Q) {
        cin >> t;
        if (t == 1) {
            cin >> r1 >> c1;
            r1--;
            c1--;
            square[r1][c1] = 1;
            if (r1 > 0 && square[r1 - 1][c1] == 1)
                uf.unite(r1 * W + c1, (r1 - 1) * W + c1);
            if (c1 > 0 && square[r1][c1 - 1] == 1)
                uf.unite(r1 * W + c1, r1 * W + c1 - 1);
            if (r1 < H - 1 && square[r1 + 1][c1] == 1)
                uf.unite(r1 * W + c1, (r1 + 1) * W + c1);
            if (c1 < W - 1 && square[r1][c1 + 1] == 1)
                uf.unite(r1 * W + c1, r1 * W + c1 + 1);
        } else {
            cin >> r1 >> c1 >> r2 >> c2;
            r1--;
            c1--;
            r2--;
            c2--;
            if (square[r1][c1] == 1 && square[r2][c2] == 1) {
                if (uf.issame(r1 * W + c1, r2 * W + c2))
                    cout << "Yes" << endl;
                else
                    cout << "No" << endl;
            } else {
                cout << "No" << endl;
            }
        }
    }

    return 0;
}
