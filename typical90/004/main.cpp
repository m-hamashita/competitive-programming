#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  ll H, W;
  cin >> H >> W;
  int A[H][W];
  rep(i, H) {
    rep(j, W) { cin >> A[i][j]; }
  }
  int row[H];
  rep(i, H) row[i] = 0;
  int column[W];
  rep(i, W) column[i] = 0;
  rep(i, H) {
    rep(j, W) {
      row[i] += A[i][j];
      column[j] += A[i][j];
    }
  }
  rep(i, H) {
    rep(j, W) {
      cout << row[i] + column[j] - A[i][j];
      if (j != W - 1)
        cout << " ";
    }
    cout << endl;
  }

  return 0;
}
