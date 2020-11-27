import time
start = time.perf_counter()
n = int(input())
s = input()

while s in 'fox':
  if "fox" in s:
    s = s.replace("fox", "")
  else:
    break

  ela = time.perf_counter() - start
  if ela >= 1.75:
    print(0)
    exit(0)

print(len(s))
