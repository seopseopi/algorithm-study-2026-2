// BOJ 1715 카드 정렬하기 (Gold IV)
// 탐욕적 알고리즘 + 우선순위 큐(최소 힙)
// 시간 복잡도: O(N log N)

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    // 가장 작은 값이 먼저 나오는 최소 힙
    priority_queue<long long, vector<long long>, greater<long long>> pq;
    for (int i = 0; i < n; i++) {
        long long size;
        cin >> size;
        pq.push(size);
    }

    // 비교 횟수의 합은 int 범위를 넘을 수 있으므로 long long 사용
    long long total = 0;
    while (pq.size() > 1) {         // 묶음이 하나면 반복하지 않고 0 출력
        long long a = pq.top(); pq.pop();
        long long b = pq.top(); pq.pop();
        total += a + b;             // 두 묶음을 합치는 비교 횟수
        pq.push(a + b);             // 합친 묶음도 다음 선택 후보에 포함
    }

    cout << total << '\n';
    return 0;
}
