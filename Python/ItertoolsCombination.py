/*
Solution for Itertools.combination()
https://www.hackerrank.com/challenges/itertools-combinations/problem
 */
from itertools import combinations
x,y = input().split()
x = list(x)
x.sort()
for i in range(1,int(y)+1):
    z = list(combinations(x,i))
    for j in z:
        print(''.join(j))
