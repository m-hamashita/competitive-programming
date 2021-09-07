#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  ll N, K;
  cin >> N >> K;
  ll A[N], B[N];
  rep(i, N) cin >> A[i];
  rep(i, N) cin >> B[i];
  int sum_operation = 0;
  rep(i, N) sum_operation += abs(A[i] - B[i]);
  if (sum_operation > K || (K - sum_operation) % 2 == 1)
    cout << "No" << endl;
  else
    cout << "Yes" << endl;

  return 0;
}
