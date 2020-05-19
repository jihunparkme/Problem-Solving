S = input()

tmp, ans, isTag = '', '', False

for i in S:
    if i == ' ':
        ans += tmp[::-1] + i
        tmp = ''
    elif i == '<':
        isTag = True
        ans += tmp[::-1] + i
        tmp = ''
    elif i == '>':
        isTag = False
        ans += i
    elif isTag:
         ans += i
    else:
        tmp += i

ans += tmp[::-1]

print(ans)

###
S = input()

tmp, ans, ck = '', '', False

for i in S:
    if i == ' ':
        if not ck:
            ans += tmp[::-1] + i
            tmp = ''
        else: ans += i
    elif i == '<':
        ck = True
        ans += tmp[::-1] + i
        tmp = ''
    elif i == '>':
        ck = False
        ans += i
    else:
        if ck: ans += i
        else: tmp += i

ans += tmp[::-1]
print(ans)