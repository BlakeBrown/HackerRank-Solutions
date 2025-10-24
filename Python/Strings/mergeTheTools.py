def merge_the_tools(string, k):
    n=len(string)
    for i in range(0,n,k):
        s=''
        for ele in string[i:i+k]:
            if (ele not in s):
                s+=ele
        print(s)