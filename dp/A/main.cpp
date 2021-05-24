#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

using namespace std;

signed main() {
  int N;
  cin >> N;
  int h[N];
  rep(i, N) cin >> h[i];
  int cost[N];
  rep(i, N) cost[i] = 10000000000;
  cost[0] = 0;
  for (int i = 0; i < N; i++) {
    if (i < N - 1)
      cost[i + 1] = min(cost[i + 1], cost[i] + abs(h[i] - h[i + 1]));
    if (i < N - 2)
      cost[i + 2] = min(cost[i + 2], cost[i] + abs(h[i] - h[i + 2]));
  }
  cout << cost[N - 1] << endl;
  return 0;
}
#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

using namespace std;

signed main() {
  int N;
  cin >> N;
  int h[N];
  rep(i, N) cin >> h[i];
  int cost[N];
  rep(i, N) cost[i] = 10000000000;
  cost[0] = 0;
  for (int i = 0; i < N; i++) {
    if (i < N - 1)
      cost[i + 1] = min(cost[i + 1], cost[i] + abs(h[i] - h[i + 1]));
    if (i < N - 2)
      cost[i + 2] = min(cost[i + 2], cost[i] + abs(h[i] - h[i + 2]));
  }
  cout << cost[N - 1] << endl;
  return 0;
}
