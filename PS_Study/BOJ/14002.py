N, A = int(input()), list(map(int, input().split()))
DP = [1 for _ in range(N)]
rev = [i for i in range(N)]
max_idx = 0

for i in range(N):
    for j in range(i):
        if A[i] > A[j] and DP[i] < DP[j] + 1:
            DP[i] = DP[j] + 1
            rev[i] = j

        if DP[max_idx] < DP[i]:
            max_idx = i

tmp = []
while max_idx != rev[max_idx]:
    tmp.append(A[max_idx])
    max_idx = rev[max_idx]
tmp.append(A[max_idx]), tmp.reverse()

print(max(DP))
for i in tmp:
    print(i, end=' ')