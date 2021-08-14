/*
Solution For: collections.OrderedDict
https://www.hackerrank.com/challenges/py-collections-ordereddict/problem
*/
from collections import OrderedDict
n = int(input())
ordered_dictionary = OrderedDict({})
for i in range(n):
    x = input().split(' ')
    y = int(x[-1])
    x.pop()
    x1 = ' '.join(x)
    if x1 in ordered_dictionary:
        ordered_dictionary[x1] += y
    else:
        ordered_dictionary[x1] = y
for i,j in ordered_dictionary.items():
    print(i,j)
