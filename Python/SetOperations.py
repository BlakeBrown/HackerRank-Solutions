/*
Solution For: Set .discard(), .remove() & .pop()
https://www.hackerrank.com/challenges/py-set-discard-remove-pop/problem
*/

n = int(input())
s = set(map(int, input().split()))
noc = int(input())
commands = {
    "pop" : lambda a:a.pop(),
    "remove" : lambda a,b:a.remove(b),
    "discard" : lambda a,b : a.discard(b)
}
for i in range(noc):
    z = input()
    z1 = z.split()
    command = z1[0]
    try:
        commands[command](s,int(z1[1]))
    except IndexError:
        commands[command](s)
print(sum(s))
