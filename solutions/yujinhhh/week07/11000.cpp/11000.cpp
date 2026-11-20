#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
ios::sync_with_stdio(false);
cin.tie(nullptr);

int n;
cin >> n;

vector<pair<int, int>> lectures(n);
for (int i = 0; i < n; ++i) {
cin >> lectures[i].first >> lectures[i].second;
}

sort(lectures.begin(), lectures.end());

priority_queue<int, vector<int>, greater<int>> endTimes;

for (const auto& lecture : lectures) {
int start = lecture.first;
int end = lecture.second;

if (!endTimes.empty() && endTimes.top() <= start) {
endTimes.pop();
}
endTimes.push(end);
}

cout << endTimes.size() << '\n';
return 0;
}
