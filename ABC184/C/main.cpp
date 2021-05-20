#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

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
  int r1, r2, c1, c2;
  cin >> r1 >> c1 >> r2 >> c2;
  int diff_x = r2 - r1;
  int diff_y = c2 - c1;
  if (diff_x == 0 && diff_y == 0){
    cout << 0 << endl;
    return 0;
  }
  if (abs(diff_x + diff_y) == 0 || abs(diff_x - diff_y) == 0 || abs(diff_x) + abs(diff_y) <= 3){
    cout << "1" << endl;
    return 0;
  }
  if (abs(diff_x - diff_y) % 2 == 0 || abs(diff_x - diff_y) < 6 || abs(diff_x - diff_y) <= 3 || abs(diff_x + diff_y) <= 3 ){
    cout << "2" << endl;
    return 0;
  }
  cout << "3" << endl;
  return 0;
}
