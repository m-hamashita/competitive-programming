#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  ll N;
  cin >> N;
  ll A[N];
  ll s = 0;
  rep(i, N) {
    cin >> A[i];
    s += A[i];
  }
  bool flag = false;
  ll right = 0;
  ll tmp = 0;
  // しゃくとり法的なやつでいけるか
  for (ll left = 0; left < N; left++) {
    while (1) {
      if (tmp * 10 == s) {
        flag = true;
        break;
      } else if (tmp * 10 > s) {
        tmp -= A[left];
        if (left == right)
          right = (right + 1) % N;
        break;
      } else {
        tmp += A[right];
        right = (right + 1) % N;
      }
      if (left == right) {
        break;
      }
    }
  }

  if (flag)
    cout << "Yes" << endl;
  else
    cout << "No" << endl;
  return 0;
}
