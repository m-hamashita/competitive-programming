#include <iostream>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  int H, W;
  cin >> H >> W;
  if (H == 1 || W == 1) {
    cout << H * W << endl;
    return 0;
  }
  cout << ((H + 1) / 2) * ((W + 1) / 2) << endl;

  return 0;
}
