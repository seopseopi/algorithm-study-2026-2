
import sys
import heapq

input = sys.stdin.readline

N = int(input())
lectures = []

for _ in range(N):
    start, end = map(int, input().split())
    lectures.append((start, end))

# 강의 시작 시간 기준 정렬
lectures.sort()

# 강의실별 종료 시간을 저장할 최소 힙
rooms = []

for start, end in lectures:
    # 가장 빨리 끝나는 강의실을 재사용할 수 있는 경우
    if rooms and rooms[0] <= start:
        heapq.heappop(rooms)

    # 현재 강의의 종료 시간 추가
    heapq.heappush(rooms, end)

# 필요한 최소 강의실 개수
print(len(rooms))
