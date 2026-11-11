#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::vector<int> positive, nonpositive;
    long long answer = 0;
    for (int i = 0; i < n; ++i) {
        int value;
        std::cin >> value;
        if (value > 1) positive.push_back(value);
        else if (value == 1) ++answer;
        else nonpositive.push_back(value);
    }

    std::sort(positive.begin(), positive.end(), std::greater<int>());
    std::sort(nonpositive.begin(), nonpositive.end());
    auto add_pairs = [&answer](const std::vector<int>& values) {
        std::size_t i = 0;
        for (; i + 1 < values.size(); i += 2)
            answer += static_cast<long long>(values[i]) * values[i + 1];
        if (i < values.size()) answer += values[i];
    };
    add_pairs(positive);
    add_pairs(nonpositive);
    std::cout << answer << '\n';
}
