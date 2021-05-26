#include <iomanip>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

using namespace std;

double dp[3005][3005];

signed main() {
  int N;
  cin >> N;
  double p[N];
  rep(i, N) cin >> p[i];
  rep(i, 3005) rep(j, 3005) dp[i][j] = 0.0;
  dp[0][0] = 1.0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j <= i; j++) {
      // flog と似たようなノリ
      dp[i + 1][j + 1] += dp[i][j] * p[i];     // omote
      dp[i + 1][j] += dp[i][j] * (1.0 - p[i]); // ura
    }
  }

  double result = 0.0;
  // rep(i, N) cout << dp[N][i] << " ";
  // cout << endl;
  for (int i = N / 2 + 1; i <= N; i++) {
    result += dp[N][i];
  }
  cout << fixed << setprecision(10) << result << endl;

  return 0;
}
