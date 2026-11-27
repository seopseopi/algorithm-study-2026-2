// BOJ 2212 센서 (Gold V)
// 정렬 + 탐욕적 알고리즘
// 시간 복잡도: O(N log N)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;
    vector<long long> pos(n);
    for (auto& x : pos) cin >> x;

    // 집중국이 센서 수 이상이면 센서마다 길이 0인 구간을 둘 수 있음
    if (k >= n) {
        cout << 0 << '\n';
        return 0;
    }

    sort(pos.begin(), pos.end());

    // 인접한 센서 사이의 간격 (같은 좌표면 0)
    vector<long long> gaps(n - 1);
    for (int i = 0; i + 1 < n; i++) gaps[i] = pos[i + 1] - pos[i];
    sort(gaps.begin(), gaps.end());

    // 집중국 k개 -> 경계 k-1개: 가장 큰 간격 k-1개를 제외하고 나머지를 더함
    long long answer = 0;
    for (int i = 0; i < (int)gaps.size() - (k - 1); i++) answer += gaps[i];

    cout << answer << '\n';
    return 0;
}
