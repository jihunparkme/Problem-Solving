S, res = input(), 0
for i in range(1, len(S)):
    if S[i] != S[i-1]:
        res += 1

print((res+1)//2)