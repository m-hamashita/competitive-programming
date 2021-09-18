#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;
const int MOD       = 1000000007;

using namespace std;

signed main() {
    ll K;
    cin >> K;
    if (K % 9 != 0) {
        cout << 0 << endl;
        return 0;
    }

    ll dp[K + 10];
    rep(i, K + 10) dp[i] = 0;
    dp[0]                = 1;
    for (int i = 0; i < K; i++) {
        for (int j = 1; j < 10; j++) {
            dp[i + j] = (dp[i + j] + dp[i]) % MOD;
        }
    }
    cout << dp[K] << endl;
    return 0;
}
