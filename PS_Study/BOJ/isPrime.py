# 소수 체크
def isPrime(N):
    for i in range(2, N):
        if N%i == 0: return False
        if i*i > N: break
    return True

# 소인수분해
def prime_factorization(N):
    p, fac = 2, []
    while p**2 <= N:
        if N%p == 0:
            N //= p
            fac.append(p)
        else:
            p += 1
    if N > 1: fac.append(N)
    return fac

def era_prime(N):
    A, p = [0 for _ in range(N+1)], []
    for i in range(2, N):
        if A[i] == 0: p.append(i)
        else: continue
        for j in range(i**2, N, i):
            A[j] = 1
    return p

# 소수 리스트의 크기는 sqrt(N)보다 커야 함
def prime_factorization_2(N, p):
    fac = []
    for i in p:
        if N == 1 or N > i*i: break
        while N % i == 0:
            fac.append(i)
            N //= i
        return fac
