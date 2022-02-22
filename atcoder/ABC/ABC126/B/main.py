s = input()

import re
yymm = re.match(r'\d\d(0[1-9]|1[0-2])', s)
mmyy = re.match(r'(0[1-9]|1[0-2])\d\d', s)

if yymm and mmyy:
   print('AMBIGUOUS')
elif yymm:
   print('YYMM')
elif mmyy:
   print('MMYY')
else:
   print('NA')