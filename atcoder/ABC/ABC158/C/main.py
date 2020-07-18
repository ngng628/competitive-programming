import math

def main():
    A, B = map(int, input().split())

    for i in range(1, 1250):
        if math.floor(0.08*i) == A and math.floor(0.1*i) == B:
            print(i)
            return

    print('-1')
    return

if __name__ == "__main__":
    main()
