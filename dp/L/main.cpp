#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

signed main() {
  int N;
  cin >> N;
  int a[N];
  rep(i, N) cin >> a[i];
  ll dp[N][N];
  rep(i, N) dp[i][i] = a[i];
  for (int bit = 1; bit < N; bit++) {
    for (int l = 0; l + bit < N; l++) {
      int r = l + bit;
      // 左取ったときと右取ったときの最大値を取る
      // 次の手番は相手なので，a[l] - dp[l+1][r], a[r] - dp[l][r-1] の max
      // bit により，それまでの(dp[l+1][r]など)dpは計算済み
      dp[l][r] = a[l] - dp[l + 1][r];
      if (r > 0)
        dp[l][r] = max(dp[l][r], a[r] - dp[l][r - 1]);
    }
  }

  cout << dp[0][N - 1] << endl;
  return 0;
}
