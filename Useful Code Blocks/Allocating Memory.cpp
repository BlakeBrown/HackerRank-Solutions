// http://www.cplusplus.com/doc/tutorial/dynamic/
// Normal declarations will allocate memory on the STACK 
// To summarize the stack (http://gribblelab.org/CBootcamp/7_Memory_Stack_vs_Heap.html): 
// - The stack grows and shrinks as functions push and pop local variables (just like a "stack" datastructure)
// - There is no need to manage the memory yourself, variables are allocated and freed automatically
// - The stack has size limits
// - Stack variables only exist while the function that created them, is running
int array[1000];
// We can also allocate memory on the heap
// To summarize the heap: 
// - Unlike the stack, the heap does not have size restrictions on variable size (apart from the obvious physical limitations of your computer)
// - Unlike the stack, variables created on the heap are accessible by any function, anywhere in your program. Heap variables are essentially global in scope.
// - Unlike the stack, the memory is not managed for you and if you fail to free()/delete the memory you allocated, you'll have a memory leak
int *array = new int[1000];

// Double array in C++
int **adjacency_matrix = new int*[N];
for(int i = 0; i < N; i++) {
	adjacency_matrix[i] = new int[N];
	for(int j = 0; j < N; j++) {
		adjacency_matrix[i][j] = -1;
	}
}



// Stack vs Heap Pros and Cons

// Stack
// - very fast access
// - don't have to explicitly de-allocate variables
// - space is managed efficiently by CPU, memory will not become fragmented
// - local variables only
// - limit on stack size (OS-dependent)
// - variables cannot be resized

// Heap
// - variables can be accessed globally
// - no limit on memory size
// - (relatively) slower access
// - no guaranteed efficient use of space, memory may become fragmented over time as blocks of memory are allocated, then freed
// - you must manage memory (you're in charge of allocating and freeing variables)
// - variables can be resized using realloc()