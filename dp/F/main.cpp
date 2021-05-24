#include <iostream>
#include <string>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;

int dp[3005][3005];
signed main() {
  string S, T;
  cin >> S >> T;

  rep(i, 3005) rep(j, 3005) dp[i][j] = 0;
  for (int i = 0; i < (int)S.size(); i++) {
    for (int j = 0; j < (int)T.size(); j++) {
      if (S[i] == T[j]) {
        dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + 1);
      }
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j + 1]);
      dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i + 1][j]);
    }
  }

  string result = "";
  int i = (int)S.size();
  int j = (int)T.size();
  while (i > 0 && j > 0) {
    if (dp[i][j] == dp[i - 1][j]) {
      i--;
    } else if (dp[i][j] == dp[i][j - 1]) {
      j--;
    } else {
      result = S[i - 1] + result;
      i--;
      j--;
    }
  }
  cout << result << endl;

  return 0;
}
