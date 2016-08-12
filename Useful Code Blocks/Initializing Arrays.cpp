// Vectors
#include <vector>
vector<int> myVector;
myVector.push_back(num);    

// 2D array
int **adjacency_matrix = new int*[N];
for(int i = 0; i < N; i++) {
	adjacency_matrix[i] = new int[N];
	for(int j = 0; j < N; j++) {
		adjacency_matrix[i][j] = -1;
	}
}

// Memset = set an existing block of memory (in this case an array) to a specified value (in this case zero)
#include <string.h>
int *array = new int[N];
memset(array, 0, sizeof(array));