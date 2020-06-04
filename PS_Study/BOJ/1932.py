N = int(input())
arr = [[0 for _ in range(N+1)] for __ in range(N+1)]
dp = [[0 for _ in range(N+1)] for __ in range(N+1)]

for i in range(1, N+1):
    tmp = list(map(int, input().split()))
    for j in range(1, i+1):
        arr[i][j] = tmp[j-1]

for i in range(1, N+1):
    for j in range(1, N+1):
        dp[i][j] = max(dp[i-1][j-1], dp[i-1][j]) + arr[i][j]

print(max(dp[-1]))