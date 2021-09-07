#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  ll N, P, Q;
  cin >> N >> P >> Q;
  ll A[N];
  rep(i, N) cin >> A[i];
  ll result = 0;
  for (int i = 0; i < N; i++) {
    for (int j = i + 1; j < N; j++) {
      for (int k = j + 1; k < N; k++) {
        for (int l = k + 1; l < N; l++) {
          for (int m = l + 1; m < N; m++) {
            ll tmp = 1;
            // % の優先順位は乗算除算と同じなのでこれで大丈夫
            tmp = A[i] * A[j] % P * A[k] % P * A[l] % P * A[m] % P;
            if (tmp == Q)
              result++;
          }
        }
      }
    }
  }

  cout << result << endl;
  return 0;
}
