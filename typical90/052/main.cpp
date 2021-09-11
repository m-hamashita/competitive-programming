#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;
const int MOD = 1000000007;

using namespace std;

signed main() {
  ll N;
  cin >> N;
  ll A[N];
  ll a1, a2, a3, a4, a5, a6;
  rep(i, N) {
    cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
    A[i] = a1 + a2 + a3 + a4 + a5 + a6;
  }
  ll result = 1;
  rep(i, N) { result = (result * A[i]) % MOD; }
  cout << result << endl;

  return 0;
}
