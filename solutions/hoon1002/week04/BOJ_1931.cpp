// BOJ 1931 회의실 배정 (Gold V)
// 정렬 + 탐욕적 알고리즘
// 시간 복잡도: O(N log N)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    // 시간은 최대 2^31 - 1이라 int에 들어가지만, 안전하게 long long 사용
    vector<pair<long long, long long>> meetings(n);  // {종료 시간, 시작 시간}
    for (auto& m : meetings) cin >> m.second >> m.first;

    // 종료 시간 오름차순, 종료 시간이 같으면 시작 시간 오름차순
    sort(meetings.begin(), meetings.end());

    int count = 0;
    long long lastEnd = 0;  // 마지막으로 선택한 회의의 종료 시간
    for (const auto& [end, start] : meetings) {
        // 끝나는 시각에 바로 시작할 수 있으므로 등호 포함
        if (start >= lastEnd) {
            count++;
            lastEnd = end;
        }
    }

    cout << count << '\n';
    return 0;
}
