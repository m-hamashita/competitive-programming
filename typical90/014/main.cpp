#include <algorithm>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  ll N;
  cin >> N;
  ll A[N], B[N];
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  sort(A, A + N);
  sort(B, B + N);
  ll result = 0;
  rep(i, N) result += abs(A[i] - B[i]);
  cout << result << endl;

  return 0;
}
