#include <iostream>
#include <map>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  int N, M;
  cin >> N >> M;
  map<int, int> mp;
  int a, b;
  rep(i, M) {
    cin >> a >> b;
    if (a > b) {
      mp[a - 1]++;
    } else {
      mp[b - 1]++;
    }
  }
  int result = 0;
  rep(i, N) {
    if (mp[i] == 1) {
      result++;
    }
  }

  cout << result << endl;
  return 0;
}
