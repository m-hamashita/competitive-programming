#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;
const int MOD       = 1000000007;
using namespace std;

signed main() {
    ll N;
    string S;
    string ans = "atcoder";
    cin >> N >> S;
    ll dp[N + 1][8];
    rep(i, 8) dp[0][i]     = 0;
    rep(i, N + 1) dp[i][0] = 1;
    for (int i = 1; i < N + 1; i++) {
        for (int j = 1; j < 8; j++) {
            if (S[i - 1] == ans[j - 1]) {
                dp[i][j] = (dp[i - 1][j] + dp[i - 1][j - 1]) % MOD;
            } else {
                dp[i][j] = dp[i - 1][j] % MOD;
            }
        }
    }
    cout << dp[N][7] << endl;

    return 0;
}
