#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> meetings;
    meetings.reserve(n);
    for (int i = 0; i < n; ++i) {
        int start, end;
        std::cin >> start >> end;
        meetings.emplace_back(end, start);
    }
    std::sort(meetings.begin(), meetings.end());

    int count = 0;
    int last_end = 0;
    for (const auto& [end, start] : meetings) {
        if (start >= last_end) {
            ++count;
            last_end = end;
        }
    }
    std::cout << count << '\n';
}
