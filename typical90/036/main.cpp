#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    ll N, Q;
    cin >> N >> Q;
    ll x[N], y[N];
    ll tmp;
    rep(i, N) {
        cin >> x[i] >> y[i];
        tmp = x[i] - y[i];
        y[i] = x[i] + y[i];
        x[i] = tmp;
    }
    ll max_x = -1 * INF, max_y = -1 * INF, min_x = INF, min_y = INF;
    rep(i, N) {
        max_x = max(max_x, x[i]);
        max_y = max(max_y, y[i]);
        min_x = min(min_x, x[i]);
        min_y = min(min_y, y[i]);
    }
    ll q;
    rep(i, Q) {
        cin >> q;
        cout << max(max(max(abs(x[q - 1] - min_x), abs(x[q - 1] - max_x)), abs(y[q - 1] - min_y)),
                    abs(y[q - 1] - max_y))
             << endl;
    }

    return 0;
}
