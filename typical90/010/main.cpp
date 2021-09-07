#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  ll N;
  cin >> N;
  int C[2][N], cls, P;
  int ruiseki[2][N + 1];
  rep(i, N + 1) {
    ruiseki[0][i] = 0;
    ruiseki[1][i] = 0;
  }
  rep(i, N) {
    cin >> cls >> P;
    if (cls == 1) {
      C[0][i] = P;
      C[1][i] = 0;
    } else {
      C[1][i] = P;
      C[0][i] = 0;
    }
  }
  rep(i, N) {
    ruiseki[0][i + 1] = ruiseki[0][i] + C[0][i];
    ruiseki[1][i + 1] = ruiseki[1][i] + C[1][i];
  }
  int Q;
  cin >> Q;
  int L, R;
  rep(i, Q) {
    cin >> L >> R;
    cout << ruiseki[0][R] - ruiseki[0][L - 1] << " "
         << ruiseki[1][R] - ruiseki[1][L - 1] << endl;
  }

  return 0;
}
