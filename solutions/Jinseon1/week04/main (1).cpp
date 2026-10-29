#include <iostream>
#include <algorithm>
#include <utility>
using namespace std;

pair<int, int> meeting[100000];

int main() {
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> meeting[i].second >> meeting[i].first;
    }

    sort(meeting, meeting + n);

    int last = 0;
    int cnt = 0;

    for (int i = 0; i < n; i++) {
        if (meeting[i].second >= last) {
            cnt++;
            last = meeting[i].first;
        }
    }

    cout << cnt << '\n';

    return 0;
}
