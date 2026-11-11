// BOJ 1744 수 묶기 (Gold IV)
// 정렬 + 탐욕적 알고리즘
// 시간 복잡도: O(N log N)

#include <bits/stdc++.h>
using namespace std;

// 정렬된 그룹을 앞에서부터 두 개씩 묶어 곱하고, 하나가 남으면 그대로 더한다
long long pairSum(const vector<int>& v) {
    long long sum = 0;
    size_t i = 0;
    for (; i + 1 < v.size(); i += 2) sum += (long long)v[i] * v[i + 1];
    if (i < v.size()) sum += v[i];
    return sum;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<int> positives;      // 1보다 큰 양수: 묶으면 이득
    vector<int> nonPositives;   // 0 이하: 음수끼리 묶거나 남은 음수를 0과 묶음
    long long answer = 0;

    for (int i = 0; i < n; i++) {
        int x;
        cin >> x;
        if (x > 1) positives.push_back(x);
        else if (x == 1) answer += 1;   // 1은 묶으면 손해이므로 바로 더함
        else nonPositives.push_back(x);
    }

    // 큰 양수끼리 묶기 위해 내림차순
    sort(positives.begin(), positives.end(), greater<int>());
    // 절댓값이 큰 음수끼리 묶기 위해 오름차순 (0은 뒤쪽에 위치)
    sort(nonPositives.begin(), nonPositives.end());

    answer += pairSum(positives);
    answer += pairSum(nonPositives);

    cout << answer << '\n';
    return 0;
}
