#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n, k;
    cin >> n >> k;

    int sensor[10000];
    int gap[10000];

    for (int i = 0; i < n; i++)
        cin >> sensor[i];

    if (k >= n) {
        cout << 0;
        return 0;
    }

    sort(sensor, sensor + n);

    for (int i = 0; i < n - 1; i++)
        gap[i] = sensor[i + 1] - sensor[i];

    sort(gap, gap + n - 1);

    int answer = 0;

    for (int i = 0; i < n - k; i++)
        answer += gap[i];

    cout << answer;

    return 0;
}
