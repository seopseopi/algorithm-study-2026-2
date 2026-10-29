#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    vector<pair<int, int>> meetings(n);
    for (auto& meeting : meetings) {
        cin >> meeting.second >> meeting.first;
    }
    // 종료 시간, 시작 시간 순서로 오름차순 정렬한다.
    sort(meetings.begin(), meetings.end());

    int lastEnd = 0;
    int answer = 0;
    for (const auto& [end, start] : meetings) {
        if (start >= lastEnd) {
            ++answer;
            lastEnd = end;
        }
    }

    cout << answer << '\n';
    return 0;
}
