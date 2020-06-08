DP = [1, 0, 0, 0, 0, 0, 0, 0]
# 0 : 정보과학관
# 1 : 전산관
# 2 : 신앙관
# 3 : 미래관
# 4 : 진리관
# 5 : 환경직기념관
# 6 : 학생회관
# 7 : 형남공학관
def move(state):
    tmp = [0 for _ in range(8)]
    tmp[0] = state[1] + state[3]
    tmp[1] = state[0] + state[2] + state[3]
    tmp[2] = state[1] + state[3] + state[4] + state[5]
    tmp[3] = state[0] + state[1] + state[2] + state[5]
    tmp[4] = state[2] + state[5] + state[6]
    tmp[5] = state[3] + state[2] + state[4] + state[7]
    tmp[6] = state[4] + state[7]
    tmp[7] = state[5] + state[6]

    for i in range(8):
        tmp[i] %= 1000000007

    print(tmp)
    return tmp

for i in range(int(input())):
    DP = move(DP)

print(DP[0])