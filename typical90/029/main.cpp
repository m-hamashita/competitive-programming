#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;
class segment_tree {
  private:
    int sz;
    std::vector<int> seg;
    std::vector<int> lazy;
    void push(int k) {
        if (k < sz) {  // 葉でないとき，子に伝播させる(全ての max がそれになる)
            lazy[k * 2]     = max(lazy[k * 2], lazy[k]);
            lazy[k * 2 + 1] = max(lazy[k * 2 + 1], lazy[k]);
        }
        seg[k]  = max(seg[k], lazy[k]);  // 今回は最大値なので，今までの最大値と勝負
        lazy[k] = 0;                     // リセットする
    }

    // [l, r): ノード k が表している範囲
    void update(int a, int b, int x, int k, int l, int r) {
        push(k);
        // 範囲外 [l, r), [a, b) なので
        // `b) <= [l` , `r) <= [a` 的な
        if (r <= a || b <= l)
            return;
        // l, r が a,b の範囲内なら(どちらも半開区間なので <= でとっている)
        if (a <= l && r <= b) {
            lazy[k] = x;
            push(k);
            return;
        }
        // 一部かぶる時
        update(a, b, x, k * 2, l, (l + r) >> 1);
        update(a, b, x, k * 2 + 1, (l + r) >> 1, r);
        seg[k] = max(seg[k * 2], seg[k * 2 + 1]);
    }
    int range_max(int a, int b, int k, int l, int r) {
        push(k);  // アクセスされたノードを push(lazyからsegに)
        if (r <= a || b <= l)
            return 0;
        if (a <= l && r <= b)
            return seg[k];
        int lc = range_max(a, b, k * 2, l, (l + r) >> 1);
        int rc = range_max(a, b, k * 2 + 1, (l + r) >> 1, r);
        return max(lc, rc);
    }

  public:
    segment_tree() : sz(0), seg(), lazy(){};
    segment_tree(int N) {
        sz = 1;  // size のこと(葉の)
        while (sz < N) {
            sz *= 2;  // 2の倍数(完全2分木)
        }
        seg  = std::vector<int>(sz * 2, 0);  // 木は 2^(N+1)-1 なので(index: 0 は無視する)
        lazy = std::vector<int>(sz * 2, 0);
    }
    // [l, r)の区間を x に update する
    void update(int l, int r, int x) {
        update(l, r, x, 1, 0, sz);  // root: k=1
    }
    int range_max(int l, int r) {
        return range_max(l, r, 1, 0, sz);
    }
};
signed main() {
    int W, N;
    cin >> W >> N;
    segment_tree seg(W);
    for (int i = 0; i < N; ++i) {
        int L, R;
        cin >> L >> R;
        // 0-indexed なので
        int height = seg.range_max(L - 1, R) + 1;
        seg.update(L - 1, R, height);
        cout << height << endl;
    }

    return 0;
}
