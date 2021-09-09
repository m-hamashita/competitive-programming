#include <algorithm>
#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  int N, M;
  cin >> N;
  int A[N][N];
  rep(i, N) { rep(j, N) cin >> A[i][j]; }
  cin >> M;
  int x, y;
  bool related[N][N];
  rep(i, N) {
    rep(j, N) { related[i][j] = false; }
  }
  rep(i, M) {
    cin >> x >> y;
    x--;
    y--;
    related[x][y] = true;
    related[y][x] = true;
  }
  vector<int> v(N);
  rep(i, N) v[i] = i;
  bool ok = true;
  bool goalflag = false;
  int result = 10000000;
  int tmp = 0;

  do {
    tmp = 0;
    ok = true;
    rep(i, N) {
      tmp += A[v[i]][i];
      if (i < N - 1 && related[v[i]][v[i + 1]] == true)
        ok = false;
    }
    if (ok) {
      result = min(result, tmp);
      goalflag = true;
    }
  } while (next_permutation(v.begin(), v.end()));

  if (goalflag) {
    cout << result << endl;
  } else {
    cout << -1 << endl;
  }
  return 0;
}
