import numpy as np
import matplotlib.pyplot as plt
from mpl_toolkits.mplot3d import Axes3D
import japanize_matplotlib
PI = np.pi # 円周率をPIで使えるようにする

fig = plt.figure()
ax = fig.add_subplot(111, projection="3d")

# x と y の範囲の設定
x_range = np.linspace(-3, 3, 1000)
y_range = np.linspace(-3, 3, 1000)
x, y = np.meshgrid(x_range, y_range)

# 関数を記述
z = x**3 + x**2 * y + x * y**2 + y**3

ax.plot_surface(x, y, z, cmap = "summer")
ax.contour(x, y, z, colors = "gray", offset = -1)  # 底面に等高線を描画

# 自動で軸を設定する場合は記述なし

# 手動で軸を設定する場合
# ax.set_xlim(-20, 20)
# ax.set_ylim(-20, 20)
# ax.set_zlim(-1500, 1500)

ax.set_xlabel("x")
ax.set_ylabel("y")
ax.set_zlabel("z")

plt.show() 