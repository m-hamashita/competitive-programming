#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

using namespace std;

signed main() {
  int N, W;
  cin >> N >> W;
  int w[N], v[N];
  rep(i, N) cin >> w[i] >> v[i];
  int value[N + 1][W + 1];
  rep(i, N + 1) rep(j, W + 1) value[i][j] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = W; j >= 0; j--) {
      if (j >= w[i])
        value[i + 1][j] = max(value[i][j], value[i][j - w[i]] + v[i]);
      else
        value[i + 1][j] = value[i][j];
    }
  }
  // rep(i, N + 1) {
  //   rep(j, W + 1) { cout << value[i][j] << " "; }
  //   cout << endl;
  // }
  cout << value[N][W] << endl;

  return 0;
}
