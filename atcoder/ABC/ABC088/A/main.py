N = int(input())
A = int(input())

def main():
    for i in range(0, A+1):
        if (N - i) % 500 == 0:
            print('Yes')
            return
    print('No')

if __name__ == "__main__":
    main()


