def check():
    for idx in range(3):
        if lst[idx] == lst[idx + 1]:
            return idx


mmax, cost = -1, 0

for i in range(int(input())):
    lst = sorted(list(map(int, input().split())))

    s = len(set(lst))

    if s == 1:
        cost = 50000 + lst[0] * 5000
    elif s == 2:
        if lst[0] == lst[1] and lst[2] == lst[3]:
            cost = 2000 + lst[0] * 500 + lst[3] * 500
        else:
            cost = 10000 + lst[1] * 1000
    elif s == 3:
        cost = 1000 + lst[check()] * 100
    else:
        cost = lst[3] * 100

    if cost > mmax:
        mmax = cost

print(mmax)
