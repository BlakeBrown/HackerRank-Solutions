  
import string
alpha = string.ascii_lowercase
l = []

def print_rangoli(size):
    for i in range(size):
        s = '-'.join(alpha[i:n])
        l.append((s[::-1]+s[1:]).center(4*n-3,'-'))
    print('\n'.join(l[:0:-1]+l))
