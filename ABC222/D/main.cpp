#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;
const long long MOD = 998244353;

using namespace std;

signed main() {
    ll N;
    cin >> N;
    ll a[N];
    ll b[N];
    rep(i, N) cin >> a[i];
    rep(i, N) cin >> b[i];

    ll ruiseki[2][3005];
    rep(i, 2) {
        rep(j, 3005) ruiseki[i][j] = 0;
    }
    rep(i, 3005) {
        ruiseki[0][i] = 1;
    }

    for (int i = 1; i < N + 1; i++) {
        for (int j = 0; j < 3005; j++) {
            ruiseki[1][j] = ruiseki[0][j];
            if (a[i - 1] <= j && j <= b[i - 1]) {
                if (j == 0) {
                    ruiseki[0][j] = ruiseki[1][j];
                } else {
                    ruiseki[0][j] = (ruiseki[0][j - 1] + ruiseki[1][j]) % MOD;
                }
            } else {
                if (j == 0) {
                    ruiseki[0][j] = 0;
                } else {
                    ruiseki[0][j] = ruiseki[0][j - 1];
                }
            }
        }
    }
    cout << ruiseki[0][3000] << endl;

    return 0;
}
