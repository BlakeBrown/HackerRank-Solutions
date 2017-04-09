def displayPathtoPrincess(n,grid):
	pXPos = None
	pYPos = None
	for i in range(0, n):
		for j in range(0,n):
			if grid[i][j] == "p":
				pYPos = i
				pXPos = j
	movesX = pXPos - (n-1)//2
	movesY = pYPos - (n-1)//2
	if(movesX < 0):
		for i in range(0, abs(movesX)):
			print("LEFT")
	else:
		for i in range(0, movesX):
			print("RIGHT")
	if(movesY < 0):
		for i in range(0, abs(movesY)):
			print("UP")
	else:
		for i in range(0, movesY):
			print("DOWN")

n = int(input())
grid = [] 
for i in range(0, n): 
    grid.append(input().strip())

displayPathtoPrincess(n,grid)
