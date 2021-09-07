#include <iostream>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  ll Q;
  cin >> Q;
  vector<ll> front;
  vector<ll> back;
  int t, x;
  rep(i, Q) {
    cin >> t >> x;
    if (t == 1) {
      front.push_back(x);
    } else if (t == 2) {
      back.push_back(x);
    } else {
      if (x > front.size()) {
        cout << back[x - front.size() - 1] << endl;
      } else {
        cout << front[front.size() - x] << endl;
      }
    }
  }

  return 0;
}
