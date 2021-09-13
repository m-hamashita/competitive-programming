#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll unsigned long long

using namespace std;
unsigned long long getDigit(unsigned long long num) {
  unsigned long long digit = 0;
  while (num != 0) {
    digit++;
    num /= 10;
  }
  return digit;
}

unsigned long long lpow(unsigned long long x, unsigned long long y) {
  unsigned long long ret = 1;
  while (y) {
    if (y & 1)
      ret = ret * x;
    x = x * x;
    y >>= 1;
  }
  return ret;
}

unsigned long long pow_mod(unsigned long long x, unsigned long long y,
                           unsigned long long MOD) {
  unsigned long long ret = 1;
  while (y) {
    if (y & 1)
      ret = ret * x % MOD;
    x = x * x % MOD;
    y >>= 1;
  }
  return ret;
}

// a^{-1} mod を計算する (フェルマーの小定理)
unsigned long long modinv(unsigned long long a, unsigned long long mod) {
  return pow_mod(a, mod - 2, mod);
}
unsigned long long getCharNum(unsigned long long left, unsigned long long right,
                              unsigned long long MOD) {
  return ((((left + right) % MOD) * ((right - left + 1) % MOD) % MOD) *
          modinv(2, MOD)) %
         MOD;
}

signed main() {
  const ll MOD = 1000000007;
  ll L, R;
  cin >> L >> R;
  ll L_length = getDigit(L);
  ll R_length = getDigit(R);
  ll result = (getCharNum(L, R, MOD) * L_length) % MOD;
  for (ll i = L_length; i <= R_length - 1; i++) {
    ll tmp = lpow(10, i);
    result = (result + (getCharNum(tmp, R, MOD) % MOD)) % MOD;
  }
  cout << result % MOD << endl;

  return 0;
}
