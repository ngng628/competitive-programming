Smax = input()
Smin = Smax

Smax = int(Smax.replace('?', '9')) - 5
Smin = int(Smin.replace('?', '0')) - 5
print(Smax)
print(Smin)

if not Smax % 13 == 0:
    Smax -= Smax % 13
if not Smin % 13 == 0:
    Smin += 13 - Smin % 13

ans = (Smax//13 - Smin//13)
print(ans % 1000000007)

