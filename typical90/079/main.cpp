#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  int H, W;
  cin >> H >> W;
  int A[H][W];
  int B[H][W];
  rep(i, H) {
    rep(j, W) { cin >> A[i][j]; }
  }
  rep(i, H) {
    rep(j, W) { cin >> B[i][j]; }
  }
  int diff[H][W];
  rep(i, H) {
    rep(j, W) { diff[i][j] = B[i][j] - A[i][j]; }
  }
  ll result = 0;
  rep(i, H - 1) {
    rep(j, W - 1) {
      result += abs(diff[i][j]);
      diff[i + 1][j] -= diff[i][j];
      diff[i][j + 1] -= diff[i][j];
      diff[i + 1][j + 1] -= diff[i][j];
      diff[i][j] -= diff[i][j];
    }
  }
  rep(i, H) {
    rep(j, W) {
      if (diff[i][j] != 0) {
        cout << "No" << endl;
        return 0;
      }
    }
  }
  cout << "Yes" << endl;
  cout << result << endl;
  return 0;
}
