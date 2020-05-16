N, S = input(), input()

score, bonus = 0, 0

for idx, res in enumerate(S):
    if res == 'O' :
        score, bonus = score + idx + 1 + bonus, bonus + 1
    else:
        bonus = 0

print(score)
