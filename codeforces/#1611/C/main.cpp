#include <bits/stdc++.h>

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
const long long INF = 1LL << 60;

using namespace std;

signed main() {
    ll N, t;
    cin >> t;
    rep(j, t) {
        cin >> N;
        deque<int> v;
        deque<int> w;
        int A[N];
        int tmp;
        rep(i, N) {
            cin >> A[i];
            v.push_back(A[i]);
        }
        int length = v.size();
        for (int i = 0; i < length - 1; i++) {
            if (v.front() < v.back()) {
                w.push_front(v.front());
                v.pop_front();
            } else {
                w.push_back(v.back());
                v.pop_back();
            }
        }
        tmp = v.front();
        v.pop_front();
        w.push_front(tmp);
        for (int i = 0; i < length - 1; i++) {
            if (w.front() < w.back()) {
                v.push_front(w.front());
                w.pop_front();
            } else {
                v.push_back(w.back());
                w.pop_back();
            }
        }
        int tmp2 = w.front();
        v.push_front(tmp2);
        bool flag = true;
        rep(i, length) {
            if (A[i] != v[i]) {
                flag = false;
            }
        }
        if (flag) {
            deque<int> v;
            deque<int> w;
            rep(i, N) {
                v.push_back(A[i]);
            }
            for (int i = 0; i < length - 1; i++) {
                if (v.front() < v.back()) {
                    w.push_front(v.front());
                    v.pop_front();
                } else {
                    w.push_back(v.back());
                    v.pop_back();
                }
            }
            w.push_front(v.front());
            rep(i, length) {
                if (i != length - 1)
                    cout << w[i] << " ";
                else
                    cout << w[i] << endl;
            }
            continue;
        }
        v.pop_front();
        v.push_back(tmp2);
        flag = true;
        rep(i, length) {
            if (A[i] != v[i]) {
                flag = false;
            }
        }
        if (flag) {
            v = {};
            w = {};
            rep(i, N) {
                v.push_back(A[i]);
            }
            for (int i = 0; i < length - 1; i++) {
                if (v.front() < v.back()) {
                    w.push_front(v.front());
                    v.pop_front();
                } else {
                    w.push_back(v.back());
                    v.pop_back();
                }
            }
            w.push_front(v.front());
            rep(i, length) {
                if (i != length - 1)
                    cout << w[i] << " ";
                else
                    cout << w[i] << endl;
            }
            continue;
        }
        v = {};
        w = {};
        rep(i, N) {
            v.push_back(A[i]);
        }
        for (int i = 0; i < length - 1; i++) {
            if (v.front() < v.back()) {
                w.push_front(v.front());
                v.pop_front();
            } else {
                w.push_back(v.back());
                v.pop_back();
            }
        }
        tmp = v.front();
        v.pop_front();
        w.push_back(tmp);

        for (int i = 0; i < length - 1; i++) {
            if (w.front() < w.back()) {
                v.push_front(w.front());
                w.pop_front();
            } else {
                v.push_back(w.back());
                w.pop_back();
            }
        }
        tmp2 = w.front();
        v.push_front(tmp2);
        flag = true;
        rep(i, length) {
            if (A[i] != v[i]) {
                flag = false;
            }
        }
        if (flag) {
            deque<int> v;
            deque<int> w;
            rep(i, N) {
                v.push_back(A[i]);
            }
            for (int i = 0; i < length - 1; i++) {
                if (v.front() < v.back()) {
                    w.push_front(v.front());
                    v.pop_front();
                } else {
                    w.push_back(v.back());
                    v.pop_back();
                }
            }
            w.push_front(v.front());
            rep(i, length) {
                if (i != length - 1)
                    cout << w[i] << " ";
                else
                    cout << w[i] << endl;
            }
            continue;
        }
        v.pop_front();
        v.push_back(tmp2);
        flag = true;
        rep(i, length) {
            if (A[i] != v[i]) {
                flag = false;
            }
        }
        if (flag) {
            v = {};
            w = {};
            rep(i, N) {
                v.push_back(A[i]);
            }
            for (int i = 0; i < length - 1; i++) {
                if (v.front() < v.back()) {
                    w.push_front(v.front());
                    v.pop_front();
                } else {
                    w.push_back(v.back());
                    v.pop_back();
                }
            }
            w.push_front(v.front());
            rep(i, length) {
                if (i != length - 1)
                    cout << w[i] << " ";
                else
                    cout << w[i] << endl;
            }
            continue;
        }
        cout << -1 << endl;
    }

    return 0;
}
