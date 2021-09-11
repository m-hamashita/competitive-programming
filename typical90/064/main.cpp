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
  ll result = 0;
  rep(i, N - 1) result += abs(A[i] - A[i + 1]);
  ll diff[N];
  rep(i, N - 1) diff[i] = A[i] - A[i + 1];

  ll L, R, V;
  rep(i, Q) {
    cin >> L >> R >> V;
    ll before = 0;
    ll after = 0;
    if (L > 1) {
      before += abs(diff[L - 2]);
      diff[L - 2] -= V;
      after += abs(diff[L - 2]);
    }
    if (R < N) {
      before += abs(diff[R - 1]);
      diff[R - 1] += V;
      after += abs(diff[R - 1]);
    }
    result += (after - before);
    cout << result << endl;
  }

  return 0;
}
