C, M = [0, 0, 0], [0, 0, 0]

for i in range(3):
    C[i], M[i] = map(int, input().split())

for i in range(100):
    now, nxt = i % 3, (i + 1) % 3
    M[now], M[nxt] = max(M[now] - (C[nxt] - M[nxt]), 0), min(C[nxt], M[nxt] + M[now])

for i in M:
    print(i)