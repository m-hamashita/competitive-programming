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
  int value[W+1];
  rep(i, W + 1) value[i] = 0;

  for (int i = 0; i < N; i++) {
    for (int j = W; j >= w[i]; j--) {
      value[j] = max(value[j], value[j-w[i]]+v[i]);
    }
  }
  cout << value[W] << endl;

  return 0;
}
