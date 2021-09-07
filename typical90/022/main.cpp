#include <algorithm>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  ll A, B, C;
  cin >> A >> B >> C;
  int chunk = __gcd(A, __gcd(B, C));
  cout << A / chunk + B / chunk + C / chunk - 3 << endl;

  return 0;
}
