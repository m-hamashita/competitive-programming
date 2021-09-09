#include <cmath>
#include <iostream>

using namespace std;

long long lpow(long long x, long long y) {
  long long ret = 1;
  while (y) {
    if (y & 1)
      ret = ret * x;
    x = x * x;
    y >>= 1;
  }
  return ret;
}

signed main() {
  long long a, b, c;
  cin >> a >> b >> c;
  c = lpow(c, b);
  if (a < c) {
    cout << "Yes" << endl;
  } else {
    cout << "No" << endl;
  }

  return 0;
}
