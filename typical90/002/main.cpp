#include <iostream>
#include <stack>

using namespace std;
bool check(string s) {
  stack<char> st;
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '(')
      st.push(s[i]);
    else {
      if (st.empty() || st.top() != '(')
        return false;
      st.pop();
    }
  }
  return st.empty();
}

signed main() {
  int N;
  cin >> N;
  for (int i = 0; i < (1 << N); i++) {
    string s = "";
    for (int j = N - 1; j >= 0; j--) {
      if (i & (1 << j))
        s += ')';
      else
        s += '(';
    }
    if (check(s))
      cout << s << endl;
  }

  return 0;
}
