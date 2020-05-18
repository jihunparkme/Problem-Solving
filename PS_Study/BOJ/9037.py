for i in range(int(input())):
    N, child, cnt = int(input()), list(map(int, input().split())), 0

    while True:
        child = [i + 1 if i % 2 else i for i in child]

        if len(set(child)) == 1:
            print(cnt)
            break

        child = [child[i] // 2 + child[(i+1) % N] // 2 for i in range(N)]
        cnt += 1