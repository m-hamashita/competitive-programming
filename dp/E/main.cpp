#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

using namespace std;
signed main() {
  int N, W;
  cin >> N >> W;
  int w[N], v[N];
  rep(i, N) cin >> w[i] >> v[i];
  int dp[100001];

  rep(i, 100001) dp[i] = 10000000000;
  dp[0] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 100000; j >= v[i]; j--) {
      dp[j] = min(dp[j], dp[j - v[i]] + w[i]);
    }
  }
  for (int i = 100000; i >= 0; i--) {
    if (dp[i] <= W) {
      cout << i << endl;
      return 0;
    }
  }

  return 0;
}
