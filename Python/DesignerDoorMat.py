/*
Solution For: Desginer Door Mat
https://www.hackerrank.com/challenges/designer-door-mat/problem
*/

n,m = map(int,input().split())
#Abovepart
for i in range(1,((n-1)//2)+1):
    print(((2*i-1)*".|.").center(m,'-'))
#Middlepart
print("WELCOME".center(m,'-'))
#belowpart
for i in range(((n-1)//2),0,-1):
    print(((2*i-1)*".|.").center(m,'-'))
