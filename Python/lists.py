if __name__ == '__main__':
    N = int(input())
    c=[]
    for i in range(N):
        c.append(input().split())

    result=[]
    for i in range(N):
        if c[i][0]=='insert':
            result.insert(int(c[i][1]),int(c[i][2]))
        elif c[i][0]=='print':
            print(result)
        elif c[i][0]=='remove':
            result.remove(int(c[i][1]))
        elif c[i][0]=='append':
            result.append(int(c[i][1]))
        elif c[i][0]=='pop':
            result.pop()
        elif c[i][0]=='sort':
            result.sort()
        elif c[i][0]=='reverse':
            result.reverse()
