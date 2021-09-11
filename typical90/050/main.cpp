#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;
const int MOD = 1000000007;

using namespace std;

signed main() {
  ll N, L;
  cin >> N >> L;
  ll dp[N + 1];
  rep(i, N + 1) dp[i] = 0;
  dp[0] = 1;

  rep(i, N) {
    dp[i + 1] = (dp[i + 1] + dp[i]) % MOD;
    if (i + L > N) {
      continue;
    } else {
      dp[i + L] = (dp[i + L] + dp[i]) % MOD;
    }
  }
  cout << dp[N] << endl;
  return 0;
}
