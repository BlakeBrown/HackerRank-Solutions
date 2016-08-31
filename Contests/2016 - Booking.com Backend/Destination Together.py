import math

cities = list(map(int, input().split(" ")))
print(math.factorial(cities[0]+cities[1]-cities[2]-1))