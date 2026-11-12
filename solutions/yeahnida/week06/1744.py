
N = int(input())

positive = []
nonpositive = []
result = 0

# 1. 입력받은 수 분류
for _ in range(N):
    num = int(input())

    if num > 1:
        positive.append(num)
    elif num == 1:
        result += 1
    else:
        nonpositive.append(num)

# 2. 정렬
positive.sort(reverse=True)
nonpositive.sort()

# 3. 1보다 큰 양수 묶기
for i in range(0, len(positive) - 1, 2):
    result += positive[i] * positive[i + 1]

# 양수가 홀수 개라면 남은 수 더하기
if len(positive) % 2 == 1:
    result += positive[-1]

# 4. 음수와 0 묶기
for i in range(0, len(nonpositive) - 1, 2):
    result += nonpositive[i] * nonpositive[i + 1]

# 마지막에 남은 수 더하기
if len(nonpositive) % 2 == 1:
    result += nonpositive[-1]

# 5. 최종 결과 출력
print(result)
