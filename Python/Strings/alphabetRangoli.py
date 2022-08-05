from string import ascii_lowercase as chars

def print_rangoli(size):
    ans=[]
    for i in range(size):
        s='-'.join(chars[i:size])
        ans.append((s[::-1]+s[1:]).center(4*size-3,'-'))
    print('\n'.join(ans[:0:-1]+ans))