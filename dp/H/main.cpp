#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

const int MOD = 1000000007;
using namespace std;

int dp[1005][1005];
signed main() {
  int H, W;
  cin >> H >> W;
  char grid[H][W];
  rep(i, H) rep(j, W) cin >> grid[i][j];
  rep(i, 1005) rep(j, 1005) dp[i][j] = 0;
  dp[1][1] = 1;
  rep(i, H) {
    rep(j, W) {
      if (i == 0 && j == 0)
        continue;
      if (grid[i][j] == '.') {
        dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j];
      }
      dp[i + 1][j + 1] %= MOD;
    }
  }

  cout << dp[H][W] << endl;
  return 0;
}
