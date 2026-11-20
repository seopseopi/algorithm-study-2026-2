#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

pair<int, int> lecture[200001];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> lecture[i].first >> lecture[i].second;
    }

    sort(lecture, lecture + n);

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++) {
        if (!pq.empty() && pq.top() <= lecture[i].first) {
            pq.pop();
        }
        pq.push(lecture[i].second);
    }

    cout << pq.size();
    return 0;
}
