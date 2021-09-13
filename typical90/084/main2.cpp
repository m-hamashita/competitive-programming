#include <iostream>
#include <string>
#include <vector>

#define ll long long

using namespace std;

signed main() {
  ll N;
  string S;
  cin >> N >> S;
  ll result = N * (N + 1) / 2;
  vector<ll> vec;
  char before;
  ll count = 0;
  for (ll i = 0; i < N; i++) {
    if (i == 0) {
      before = S[i];
      count++;
      continue;
    }
    if (before == S[i]) {
      count++;
    } else {
      vec.push_back(count);
      count = 1;
    }
    before = S[i];
  }
  vec.push_back(count);
  for (auto num : vec) {
    result = result - num * (num + 1) / 2;
  }
  cout << result << endl;

  return 0;
}
