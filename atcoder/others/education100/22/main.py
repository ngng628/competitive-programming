import scipy.optimize
import numpy as np

k = 2/3 * np.log(2)
P = float(input())

def f(t):
    return t + P*2**(-t/1.5)

def diff_f(t):
    return 1 - P*k*2**(-t/1.5)

def main():
    x0 = scipy.optimize.bisect(diff_f, -100, P+1)
    print('{:.9}'.format(f(max(0, x0))))

if __name__ == "__main__":
    main()
