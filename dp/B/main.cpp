#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define int long long

using namespace std;

signed main() {
  int N, K;
  cin >> N >> K;
  int h[N];
  rep(i, N) cin >> h[i];
  int cost[N];
  rep(i, N) cost[i] = 100000000000;
  cost[0] = 0;
  for (int i=0;i<N;i++){
    for (int j=1;((j<K+1) && (i+j<N));j++){
      cost[i+j] = min(cost[i+j], cost[i] + abs(h[i]-h[i+j]));
    }
  }
  cout << cost[N-1] << endl;

  return 0;
}
