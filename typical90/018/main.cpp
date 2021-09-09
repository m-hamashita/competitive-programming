#include <cmath>
#include <iomanip>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  double T, L, X, Y, E;
  ll Q;
  cin >> T >> L >> X >> Y >> Q;
  double y_tmp, z_tmp, y_diff, bottom;
  rep(i, Q) {
    cin >> E;
    y_tmp = L / 2.0 * cos(-M_PI / 2.0 - 2.0 * E / T * M_PI);
    z_tmp = L / 2.0 * sin(-M_PI / 2.0 - 2.0 * E / T * M_PI) + L / 2.0;
    y_diff = abs(Y - y_tmp);
    bottom = sqrt(pow(X, 2) + pow(y_diff, 2));
    cout << setprecision(12) << atan2(z_tmp, bottom) / M_PI * 180.0 << endl;
  }

  return 0;
}
