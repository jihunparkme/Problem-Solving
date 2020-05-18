lst = sorted(list(map(int, input().split())))

s = len(set(lst))
if s == 3:
    print(lst[2] * 100)
elif s == 2:
    print(1000 + lst[1] * 100)
else:
    print(10000 + lst[0] * 1000)