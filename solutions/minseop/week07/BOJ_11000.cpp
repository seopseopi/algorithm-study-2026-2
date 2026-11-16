#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<std::pair<int, int>> lectures(n);
    for (auto& [start, end] : lectures) std::cin >> start >> end;
    std::sort(lectures.begin(), lectures.end());

    std::priority_queue<int, std::vector<int>, std::greater<int>> ends;
    for (const auto& [start, end] : lectures) {
        if (!ends.empty() && ends.top() <= start) ends.pop();
        ends.push(end);
    }
    std::cout << ends.size() << '\n';
}
