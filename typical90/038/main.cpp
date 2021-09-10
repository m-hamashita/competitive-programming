#include <algorithm>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)

using namespace std;

signed main() {
  unsigned long long A, B;
  cin >> A >> B;
  A = A / __gcd(A, B);
  if (A > 1000000000000000000LL / B) {
    cout << "Large" << endl;
  } else {
    cout << A * B << endl;
  }

  return 0;
}
