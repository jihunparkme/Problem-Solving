# 1. 소인수의 개수 구하기 O(NlogN)
def era_factor_count(N):
    A = [0 for _ in range(N+1)]
    for i in range(1, N+1):
        for j in range(i, N+1, i):
            A[j] += 1
    return A

# 2. 소인수의 합 구하기
def era_factor_sum(N):
    A = [0 for _ in range(N+1)]
    for i in range(1, N+1):
        for j in range(i, N+1, i):
            A[j] += i
    return A

# 3. 소인수분해
def era_factorization(N):
    A = [0 for _ in range(N+1)]
    for i in range(2, N+1):
        if A[i]: continue
        for j in range(i, N+1, i):
            A[j] = i
    return A

A = era_factorization(100)
N = 84
while A[N] != 0:
    print(A[N], end=' ')
    N //= A[N]


