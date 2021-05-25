#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

using namespace std;
signed main() {
  int N, W;
  cin >> N >> W;
  int w[N], v[N];
  rep(i, N) cin >> w[i] >> v[i];
  int dp[N + 1][100001];

  rep(j, N + 1) rep(i, 100001) dp[j][i] = 1000000000000000;
  dp[0][0] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 100000; j >= 0; j--) {
      if (j >= v[i])
        dp[i + 1][j] = min(dp[i][j], dp[i][j - v[i]] + w[i]);
      else
        dp[i + 1][j] = dp[i][j];
    }
  }
  // rep(i, N + 1) {
  //   rep(j, 20) { cout << dp[i][j] << " "; }
  //   cout << endl;
  // }
  for (int i = 100000; i >= 0; i--) {
    if (dp[N][i] <= W) {
      cout << i << endl;
      return 0;
    }
  }
  return 0;
}
