#include <algorithm>
#include <cmath>
#include <iostream>
#include <set>
#include <tuple>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

long long getDigit(unsigned long long num) {
    unsigned long long digit = 0;
    while (num != 0) {
        digit++;
        num /= 10;
    }
    return digit;
}

signed main() {
    ll N;
    cin >> N;
    vector<ll> v;
    for (ll i = 1; i <= sqrt(N); i++) {
        if (N % i == 0) {
            v.push_back(i);
            v.push_back(N / i);
        }
    }
    sort(v.begin(), v.end());
    set<tuple<ll, ll, ll>> st;
    for (ll i : v) {
        for (ll j : v) {
            ll sum_digit = getDigit(i) + getDigit(j);
            if (sum_digit > 13) {  // overflow しないための適当なしきい値
                continue;
            }
            if (N < i * j)
                continue;
            ll s    = N / (i * j);
            auto it = lower_bound(v.begin(), v.end(), s);

            ll a = i;
            ll b = j;
            ll c = *it;
            if (N == (a * b * c)) {
                if (a > b) {
                    swap(a, b);
                }
                if (b > c) {
                    swap(b, c);
                }
                if (a > b) {
                    swap(a, b);
                }
                st.insert(make_tuple(a, b, c));
            }
        }
    }
    cout << st.size() << endl;

    return 0;
}
