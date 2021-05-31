#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
  int N, K;
  cin >> N >> K;
  int a[N];
  rep(i, N) cin >> a[i];
  bool dp[K + 1];
  rep(i, K + 1) dp[i] = false;
  // その時点で行動する場合勝てるかどうか.(0にできる数か?)
  for (int i = 1; i <= K; i++) {
    for (int j = 0; j < N; j++) {
      if (i >= a[j]) {
        if (dp[i - a[j]] == false) {
          dp[i] = true;
        }
      }
    }
  }

  if (dp[K] == true)
    cout << "First" << endl;
  else
    cout << "Second" << endl;

  return 0;
}
