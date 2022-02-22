def next_permutation(a):
    for i in reversed(range(len(a) - 1)):
        if a[i] < a[i + 1]:
            break
    else:
        return False

    j = next(j for j in reversed(range(i + 1, len(a))) if a[i] < a[j])

    a[i], a[j] = a[j], a[i]

    a[i + 1:] = reversed(a[i + 1:])
    return True

import os
import time

a = [20 for i in range(20)]
import subprocess
cur = 0
for cur in range(20):
   with open('./submit.txt', mode='w') as f:
      for i in range(20):
         if i == cur:
            f.write(str(1) + ' ')
         else:
            f.write(str(20) + ' ')
      f.write('\n')
   subprocess.run(['sh', './sub.sh'])
   time.sleep(5)
   os.remove('./submit.txt')