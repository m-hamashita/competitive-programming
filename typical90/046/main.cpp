#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  ll N;
  int A[46], B[46], C[46];
  cin >> N;
  int tmp;
  rep(i, 46) {
    A[i] = 0;
    B[i] = 0;
    C[i] = 0;
  }
  rep(i, N) {
    cin >> tmp;
    A[tmp % 46]++;
  }
  rep(i, N) {
    cin >> tmp;
    B[tmp % 46]++;
  }
  rep(i, N) {
    cin >> tmp;
    C[tmp % 46]++;
  }
  ll result = 0;
  rep(i, 46) {
    rep(j, 46) {
      result += (long long)(A[i]) * B[j] * C[(46 - ((i + j) % 46)) % 46];
    }
  }
  cout << result << endl;

  return 0;
}
