#include <iostream>
#include <string>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  ll N;
  string S;
  cin >> N >> S;
  ll result = 0;
  ll xCount = 0;
  ll oCount = 0;
  ll right = 0;

  for (ll left = 0; left < N; left++) {
    while (1) {
      // o と x が 1個 以上ある時それ以降全て条件を満たす
      if (xCount > 0 && oCount > 0) {
        result += N - right + 1; // right++分+1 してあげる
        break;
      }
      if (right > N - 1)
        break;
      if (S[right] == 'x') {
        xCount++;
      } else {
        oCount++;
      }
      right++;
    }
    if (S[left] == 'x') {
      xCount--;
    } else {
      oCount--;
    }
  }
  cout << result << endl;

  return 0;
}
