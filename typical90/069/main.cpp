#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

const int MOD = 1000000007;
using namespace std;

long long pow_mod(long long x, long long y, long long MOD) {
  long long ret = 1;
  while (y) {
    if (y & 1)
      ret = ret * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ret;
}

signed main() {
  ll N, K;
  cin >> N >> K;
  ll result = 1;
  if (N < 3) {
    rep(i, N) {
      result = (result * K) % MOD;
      K--;
    }
    cout << result << endl;
    return 0;
  }
  if (K < 3) {
    cout << 0 << endl;
    return 0;
  }
  result = (K * (K - 1)) % MOD;
  cout << (result * pow_mod(K - 2, N - 2, MOD)) % MOD << endl;
  return 0;
}
