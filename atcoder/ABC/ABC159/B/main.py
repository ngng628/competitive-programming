def kaibun(s):
    #print('[debug]',s)

    for i in range(len(s) // 2):
        if s[i] != s[len(s)-1 - i]:
            return False
    
    return True

def main():
    S = input()
    N = len(S)
    if kaibun(S) == False:
        #print('[debug]','if 1')
        print('No')
        return

    if kaibun(S[0:(N-1)//2]) == False:
        #print('[debug]','if 2')
        print('No')
        return
    if kaibun(S[(N+3)//2 - 1:N]) == False:
        #print('[debug]','if 3')
        print('No')
        return

    print('Yes')

if __name__ == '__main__':
    main()


