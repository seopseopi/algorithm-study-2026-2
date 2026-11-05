#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;
    priority_queue<long long, vector<long long>, greater<long long>> cards;
    for (int i = 0; i < n; ++i) {
        long long size;
        cin >> size;
        cards.push(size);
    }

    long long answer = 0;
    while (cards.size() > 1) {
        long long first = cards.top();
        cards.pop();
        long long second = cards.top();
        cards.pop();
        long long merged = first + second;
        answer += merged;
        cards.push(merged);
    }
    cout << answer << '\n';
    return 0;
}
