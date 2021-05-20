#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;
const int MOD = 1000000007;

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

long long binomial_coefficient_mod(long long n, long long r, int MOD) {
  long long fact_r = 1;
  for (int i=1;i<=r;i++){
    fact_r *= i;
    fact_r = fact_r % MOD;
  }
  long long result = pow_mod(fact_r, MOD-2, MOD);
  for(int i=n-r+1;i<=n;i++){
    result = (result * i)%MOD;
  }
  return result;
}

signed main() {
  long long n, a, b;
  long long result;
  cin >> n >> a >> b;
  result = pow_mod(2, n, MOD) - 1; // nCk の総和から0本を外す
  result -= binomial_coefficient_mod(n, a, MOD);
  result = result % MOD;
  if (result < 0) result += MOD; // MODの結果がマイナスだったら戻す
  result -= binomial_coefficient_mod(n, b, MOD);
  result = result % MOD;
  if (result < 0) result += MOD;
  cout << result << endl;

  return 0;
}
