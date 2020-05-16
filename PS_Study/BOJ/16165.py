N, M = map(int, input().split())

team_mem, mem_team = {}, {}

for i in range(N):
    teamName, memNum = input(), int(input())
    team_mem[teamName] = []
    for j in range(memNum):
        memName = input()
        team_mem[teamName].append(memName)
        mem_team[memName] = teamName

for i in range(M):
    name, q = input(), int(input())
    if q :
        print(mem_team[name])
    else:
        for mem in sorted(team_mem[name]):
            print(mem)