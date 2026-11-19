// BOJ 11000 강의실 배정 (Gold V)
// 정렬 + 탐욕적 알고리즘 + 우선순위 큐(최소 힙)
// 시간 복잡도: O(N log N)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> lectures(n);  // {시작 시간, 종료 시간}
    for (auto& l : lectures) cin >> l.first >> l.second;

    // 시작 시간 오름차순 (시작 시간이 같으면 종료 시간 오름차순)
    sort(lectures.begin(), lectures.end());

    // 각 강의실에서 마지막으로 진행한 강의의 종료 시간 (가장 작은 값이 top)
    priority_queue<int, vector<int>, greater<int>> rooms;

    for (const auto& [start, end] : lectures) {
        // 가장 빨리 비는 강의실이 현재 강의 시작 전에 끝나면 재사용
        // (끝나는 시각에 바로 시작할 수 있으므로 등호 포함)
        if (!rooms.empty() && rooms.top() <= start) rooms.pop();
        rooms.push(end);  // 재사용이면 종료 시간 갱신, 아니면 새 강의실 추가
    }

    cout << rooms.size() << '\n';  // 힙에 남은 강의실 수가 정답
    return 0;
}
