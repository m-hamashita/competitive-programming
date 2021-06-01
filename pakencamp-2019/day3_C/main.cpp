#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  ll N, M;
  cin >> N >> M;
  ll A[N][M];
  rep(i, N) rep(j, M) cin >> A[i][j];
  ll result = 0;
  ll tmp = 0;
  for (int i = 0; i < M - 1; i++) {
    for (int j = i + 1; j < M; j++) {
      tmp = 0;
      for (int k = 0; k < N; k++) {
        tmp += max(A[k][i], A[k][j]);
      }
      result = max(result, tmp);
    }
  }

  cout << result << endl;
  return 0;
}
