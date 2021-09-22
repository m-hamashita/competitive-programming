#include <algorithm>
#include <iostream>
#include <map>
#include <vector>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    string X;
    int N;
    vector<string> v;
    cin >> X >> N;
    string tmp;
    string S = "abcdefghijklmnopqrstuvwxyz";
    map<char, char> dic;
    map<char, char> rev_dic;
    rep(i, 26) {
        dic[S[i]]     = X[i];
        rev_dic[X[i]] = S[i];
    }
    // rep(i, 26) {
    //     cout << dic[S[i]];
    // }
    // cout << endl;
    // rep(i, 26) {
    //     cout << rev_dic[X[i]];
    // }
    // cout << endl;
    rep(i, N) {
        cin >> tmp;
        rep(j, tmp.size()) {
            tmp[j] = rev_dic[tmp[j]];
        }
        // cout << tmp << endl;
        v.push_back(tmp);
    }
    sort(v.begin(), v.end());
    for (string value : v) {
        rep(j, value.size()) {
            value[j] = dic[value[j]];
        }
        cout << value << endl;
    }

    return 0;
}
