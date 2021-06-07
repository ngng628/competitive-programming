import numpy as np
import matplotlib.pyplot as plt
import japanize_matplotlib
PI = np.pi  # 円周率をPIで使えるようにする

# 定義域を指定
x = np.linspace(1, 1000, 1000000)

# ここに関数を記述
y = 0.998**(1000 - x)

plt.plot(x, y)

plt.grid(which='major', color='gray', linestyle='--')
plt.grid(which='minor', color='gray', linestyle='--')
#plt.xscale("log")

# 自動で軸をとりたい場合
#plt.axes().set_aspect('equal', 'datalim')
# 手動で軸を取りたい場合
#plt.axes().set_aspect('equal')
#plt.xlim([1, 1000])
#plt.ylim([0, 1])

plt.show()
