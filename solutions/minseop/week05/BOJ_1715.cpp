#include <functional>
#include <iostream>
#include <queue>
#include <vector>

int main() {
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);

    int n;
    std::cin >> n;
    std::priority_queue<long long, std::vector<long long>, std::greater<long long>> cards;
    for (int i = 0; i < n; ++i) {
        long long size;
        std::cin >> size;
        cards.push(size);
    }

    long long total = 0;
    while (cards.size() > 1) {
        long long first = cards.top();
        cards.pop();
        long long second = cards.top();
        cards.pop();
        long long combined = first + second;
        total += combined;
        cards.push(combined);
    }
    std::cout << total << '\n';
}
