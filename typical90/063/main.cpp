#include <iostream>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    ll H, W;
    cin >> H >> W;
    ll P[H][W];
    rep(i, H) rep(j, W) cin >> P[i][j];

    bool flag[W];
    map<ll, ll> m;
    ll tmp = 0;

    ll column_max = 0;
    ll row_num    = 0;
    ll tmp_max    = 0;
    for (int i = 0; i < (1 << H); i++) {
        column_max = 0;
        row_num    = 0;
        m.clear();
        rep(i, W) flag[i] = true;
        for (int j = 0; j < H; j++) {
            if (i & (1 << j)) {
                row_num++;
                tmp = j;
                for (int k = 0; k < H; k++) {
                    if (i & (1 << k)) {
                        rep(l, W) {
                            if (P[j][l] != P[k][l])
                                flag[l] = false;
                        }
                    }
                }
            }
        }

        rep(j, W) {
            if (flag[j]) {
                m[P[tmp][j]]++;
                column_max = max(column_max, m[P[tmp][j]]);
            }
        }
        tmp_max = max(tmp_max, column_max * row_num);
    }
    cout << tmp_max << endl;

    return 0;
}
