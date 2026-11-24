import sys
input = sys.stdin.readline

N = int(input())  # 센서의 개수
K = int(input())  # 집중국의 개수
sensors = list(map(int, input().split()))

# 집중국의 수가 센서의 수 이상이면 수신 구간 길이는 0
if K >= N:
    print(0)
else:
    # 센서의 좌표를 오름차순으로 정렬
    sensors.sort()

    # 인접한 센서 사이의 거리 계산
    distances = []

    for i in range(N - 1):
        distances.append(sensors[i + 1] - sensors[i])

    # 센서 사이의 간격을 오름차순으로 정렬
    distances.sort()

    # 가장 큰 K-1개의 간격을 제외하고 합산
    result = sum(distances[:N - K])

    print(result)