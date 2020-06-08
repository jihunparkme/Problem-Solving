N, A = int(input()), sorted(list(map(int, input().split())))

W = 0
for i in A:
    if i <= W + 1:
        W += i
    else:
        break

print(W+1)