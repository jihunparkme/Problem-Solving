N, L, K = map(int, input().split())

score = 0
easy, hard = 0, 0

for prob in range(N):
    sub1, sub2 = map(int, input().split())
    if sub2 <= L:
        hard += 1
    elif sub1 <= L:
        easy += 1

score += min(hard, K) * 140
if hard < K:
    score += min(easy, K-hard) * 100

print(score)