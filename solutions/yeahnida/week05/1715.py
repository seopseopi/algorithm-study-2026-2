
import sys
import heapq

input = sys.stdin.readline

N = int(input())
cards = []

for _ in range(N):
    heapq.heappush(cards, int(input()))

total = 0

while len(cards) > 1:
    first = heapq.heappop(cards)
    second = heapq.heappop(cards)

    merged = first + second
    total += merged

    heapq.heappush(cards, merged)

print(total)
