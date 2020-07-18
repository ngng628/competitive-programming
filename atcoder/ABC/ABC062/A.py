def main():
    g = [[1, 3, 5, 7, 8, 10, 12], [4, 6, 9, 11], [2]]

    x, y = map(int, input().split())

    i1 = -1
    i2 = -1
    for i in range(len(g)):
        if g[i].count(x) == 1 and g[i].count(y) == 1:
            print('Yes')
            return

    print('No')

if __name__ == '__main__':
    main()
