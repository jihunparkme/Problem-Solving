alpa = [3,2,1,2,4,3,1,3,1,1,3,1,3,2,1,2,2,2,1,2,1,1,1,2,2,1]

N, M = map(int, input().split())
A, B = input().split()

AB = ""
min_len = min(N, M)
for i in range(min_len):
    AB += A[i] + B[i]

AB += A[min_len:] + B[min_len:]

res = [alpa[ord(i) - ord('A')] for i in AB]

for i in range(N+M-2):
    for j in range(N+M-1-i):
        res[j] += res[j+1]

print("{}%".format(res[0] % 10 * 10 + res[1] % 10))