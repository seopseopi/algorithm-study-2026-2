#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<int> positive, nonpositive;
    long long answer = 0;
    for (int i = 0; i < n; ++i) {
        int value;
        cin >> value;
        if (value > 1) positive.push_back(value);
        else if (value == 1) ++answer;
        else nonpositive.push_back(value);
    }

    sort(positive.begin(), positive.end(), greater<int>());
    sort(nonpositive.begin(), nonpositive.end());

    for (const auto& values : {positive, nonpositive}) {
        size_t i = 0;
        for (; i + 1 < values.size(); i += 2) {
            answer += 1LL * values[i] * values[i + 1];
        }
        if (i < values.size()) answer += values[i];
    }
    cout << answer << '\n';
    return 0;
}
