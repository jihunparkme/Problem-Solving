def pow_advanced(a, b, mod):
    res = 1
    while b > 0:
        if b % 2: res = res * a % mod
        a, b = a * a % mod, b // 2
    return res

print(pow_advanced(3, 1001, 10001))
print(pow(3, 1001, 10001))
print(3**1001%10001)