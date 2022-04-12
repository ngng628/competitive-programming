import datetime

def f(h, m, s):
   return '2022-05-05 {:02}:{:02}:{:02}'.format(h, m, s)

a, b, c, d = map(int, input().split())

d1 = datetime.datetime.strptime(f(a, b, 0), '%Y-%m-%d %H:%M:%S')
d2 = datetime.datetime.strptime(f(c, d, 1), '%Y-%m-%d %H:%M:%S')

if d1 < d2:
   print('Takahashi')
else:
   print('Aoki')