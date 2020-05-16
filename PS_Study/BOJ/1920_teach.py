N, A = int(input()), {i: 1 for i in map(int, input().split())}
M = input()

for i in list(map(int, input().split())):
    print(A.get(i, 0))
    # print(1 if i in A else 0)