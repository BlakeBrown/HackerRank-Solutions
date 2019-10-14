if __name__ == '__main__':
    n = int(input())
    arr = map(int, input().split())

    arr = list(arr)
    m = max(arr)
    for i in range(n):
        if arr[i] == m:
            arr[i] = -999

    print(max(arr))
