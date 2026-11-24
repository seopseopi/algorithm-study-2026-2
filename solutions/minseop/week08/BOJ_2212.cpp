#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n, k;
    std::cin >> n >> k;
    std::vector<int> sensors(n);
    for (int& sensor : sensors) std::cin >> sensor;
    std::sort(sensors.begin(), sensors.end());

    std::vector<int> gaps;
    for (int i = 1; i < n; ++i) gaps.push_back(sensors[i] - sensors[i - 1]);
    std::sort(gaps.begin(), gaps.end());

    long long result = 0;
    for (int i = 0; i < n - k; ++i) result += gaps[i];
    std::cout << result << '\n';
}
