#include <algorithm>
#include <iostream>
#include <iterator>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  int N, Q;
  cin >> N;
  ll A[N];
  rep(i, N) cin >> A[i];
  sort(A, A + N);
  cin >> Q;
  ll B;
  rep(i, Q) {
    cin >> B;
    auto it = lower_bound(A, A + N, B);
    int idx = distance(A, it);
    if (idx != 0) {
      cout << min(abs(*it - B), abs(*prev(it) - B)) << endl;
    } else {
      cout << abs(*it - B) << endl;
    }
  }
  return 0;
}
