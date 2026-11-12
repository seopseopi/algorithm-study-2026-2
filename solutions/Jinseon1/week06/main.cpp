
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, x;
    cin >> n;

    vector<int> pos, neg;
    int one = 0, zero = 0;

    for (int i = 0; i < n; i++) {
        cin >> x;

        if (x > 1) pos.push_back(x);
        else if (x == 1) one++;
        else if (x == 0) zero++;
        else neg.push_back(x);
    }

    sort(pos.begin(), pos.end(), greater<int>());
    sort(neg.begin(), neg.end());

    int ans = one;

    for (int i = 0; i + 1 < pos.size(); i += 2) {
        ans += pos[i] * pos[i + 1];
    }

    if (pos.size() % 2 == 1) {
        ans += pos.back();
    }

    for (int i = 0; i + 1 < neg.size(); i += 2) {
        ans += neg[i] * neg[i + 1];
    }

    if (neg.size() % 2 == 1 && zero == 0) {
        ans += neg.back();
    }

    cout << ans;

    return 0;
}
