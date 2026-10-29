# BOJ 1931 - 회의실 배정
# Greedy Algorithm

N = int(input())

meetings = []

for _ in range(N):
    start, end = map(int, input().split())
    meetings.append((start, end))

# 종료 시간이 빠른 순서로 정렬
# 종료 시간이 같다면 시작 시간이 빠른 순서
meetings.sort(key=lambda x: (x[1], x[0]))

count = 0
last_end = 0

for start, end in meetings:
    if start >= last_end:
        count += 1
        last_end = end

print(count)
