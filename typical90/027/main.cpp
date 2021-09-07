#include <iostream>
#include <set>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
  ll N;
  cin >> N;
  set<string> st;

  string s;
  rep(i, N) {
    cin >> s;
    if (!st.count(s))
      cout << i + 1 << endl;
    st.insert(s);
  }
  return 0;
}
