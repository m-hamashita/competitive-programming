#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

using namespace std;

int select(int dp[], int a, int b, int c, int N, int before) {
  return dp[N - 1];
}

signed main() {
  int N;
  cin >> N;
  int happy[3][N];
  rep(i, N) cin >> happy[0][i] >> happy[1][i] >> happy[2][i];
  int dp[3][N + 1];
  rep(i, N + 1) {
    dp[0][i] = 0;
    dp[1][i] = 0;
    dp[2][i] = 0;
  }

  dp[0][0] = happy[0][0];
  dp[1][0] = happy[1][0];
  dp[2][0] = happy[2][0];
  rep(i, N - 1) {
    rep(j, 3) {
      dp[j][i + 1] =
          max(dp[j][i + 1], dp[abs((j + 1) % 3)][i] + happy[j][i + 1]);
      dp[j][i + 1] =
          max(dp[j][i + 1], dp[abs((j + 2) % 3)][i] + happy[j][i + 1]);
    }
  }
  // rep(i, N){
  //   rep(j, 3){
  //     cout << dp[j][i] << " ";
  //   }
  //   cout << endl;
  // }

  cout << max(max(dp[0][N - 1], dp[1][N - 1]), dp[2][N - 1]) << endl;
  return 0;
}
