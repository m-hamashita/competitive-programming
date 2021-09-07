#include <algorithm>
#include <cmath>
#include <iostream>
#include <stdlib.h>
#include <string>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long

using namespace std;

signed main() {
  string N;
  string s = "";
  int K;
  cin >> N >> K;
  rep(i, K) {
    if (N == "0") {
      cout << "0" << endl;
      return 0;
    }
    ll tmp = 0;
    rep(j, N.length()) { tmp = tmp * 8 + (long long)(N[j] - '0'); }
    s.clear();
    while (tmp > 0) {
      s = char((tmp % 9) + '0') + s;
      tmp = tmp / 9;
    }
    rep(j, s.length()) {
      if (s[j] == '8')
        s[j] = '5';
    }
    N = s;
  }

  cout << N << endl;
  return 0;
}
