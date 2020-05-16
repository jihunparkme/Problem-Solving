N, A = int(input()), list(map(int, input().split()))
B = [A[0]]

for i in range(1, N) :
    B.append(A[i] * (i+1) - sum(B))

for i in B:
    print(i, end = ' ')