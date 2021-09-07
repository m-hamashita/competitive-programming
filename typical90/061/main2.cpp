#include <deque>
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  ll Q;
  cin >> Q;

  deque<ll> deq;
  int t, x;
  rep(i, Q) {
    cin >> t >> x;
    if (t == 1) {
      deq.push_front(x);
    } else if (t == 2) {
      deq.push_back(x);
    } else {
      cout << deq[x - 1] << endl;
    }
  }

  return 0;
}
