#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  ll N, Q;
  cin >> N >> Q;
  ll A[N];
  rep(i, N) cin >> A[i];
  int head = 0;
  int T, x, y;
  int tmp;
  rep(i, Q) {
    cin >> T >> x >> y;
    if (T == 1) {
      tmp = A[(head + x - 1) % N];
      A[(head + x - 1) % N] = A[(head + y - 1) % N];
      A[(head + y - 1) % N] = tmp;
    } else if (T == 2) {
      head = (head - 1 + N) % N;
    } else if (T == 3) {
      cout << A[(head + x - 1) % N] << endl;
    }
  }

  return 0;
}
