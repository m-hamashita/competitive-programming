#include <iostream>

#define ll long long

using namespace std;

signed main() {
  ll N;
  cin >> N;
  ll count = 0;
  for (ll i = 2; i * i <= N; i++) {
    while (N % i == 0) {
      count++;
      N /= i;
    }
  }
  if (N != 1)
    count++;
  ll result = 0;
  while (count > 1) {
    result++;
    count = (count + 1) / 2;
  }
  cout << result << endl;

  return 0;
}
