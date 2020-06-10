# 1. 단순한 반복문
def gcd_naive(a, b):
    for i in range(min(a,b), 0, -1):
        if a % i== 0 and b % i == 0: return i

# 2. 유클리드호제법을 이용
def gcd(a, b):
    if a % b == 0: return b
    return gcd(b, a % b)
    # return gcd(b, a % b) if a % b != 0 else b

# 2-2. 유클리드호제법을 반복문으로
def gcd2(a, b):
    while a % b != 0: a, b = b, a % b
    return b

# 3. math의 gcd 사용
import math
math.gcd(1, 2)

# python에서는 무관하나 다른 언어 사용 시 int overflow 발생 가능성이 있으므로
# a / gcd(a,b) * b 순서로 연산﻿
def lcm(a, b):
    return a*b / gcd(a,b)


print(gcd(10, 24))
print(gcd2(10, 24))
print(gcd_naive(10, 24))
print(math.gcd(10, 24))
