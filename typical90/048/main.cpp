#include <algorithm>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  ll N, K;
  cin >> N >> K;
  long long A[2 * N];
  int x, y;
  rep(i, N) {
    cin >> x >> y;
    A[2 * i] = x - y;
    A[2 * i + 1] = y;
  }
  sort(A, A + 2 * N);
  ll result = 0;
  rep(i, K) { result += A[2 * N - i - 1]; }
  cout << result << endl;

  return 0;
}
