A, B = map(int, input().split())
S = input()

if S[0:A].isdecimal() and S[A+1:A+1+B].isdecimal() and S[A] == '-':
    print('Yes')
else:
    print('No')

