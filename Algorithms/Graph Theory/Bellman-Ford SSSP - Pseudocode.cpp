// Belmman-Ford is an SSSP (single source shortest path) algorthim
// - When the algorithm finishes, the shortest distance from source to all other vertex's in the graph will be known
// - Bellman-Ford alsow works for graphs with negative edge weights and can detect negative cycles if they exist
// - However, if there are only positive edge weights one should use Dijkstra's instead since it has a better runtime
// Bellman-ford vs. Dijkstra's:
// - Both algorithms are based on the principle of relaxation, in which an approximation to the shortest path
// is gradually replaced by more accurate values until the optimal solution is reached.
// - However, Dijkstra's uses a priority queue to greedily select the closest vertex that has not yet been 
// processed and performs this relaxation to all of its outgoing edges. In contrast, Bellman-ford simply
// relaxes ALL of the edges V-1 times. On each iteration, the number of vertices with correctly calculated distances 
// grows, from which it follows that eventually all vertices will have their correct distances
// Total Runtime: O(VE)


function BellmanFord(list vertices, list edges, vertex source)
   ::distance[],predecessor[]

   // This implementation takes in a graph, represented as
   // lists of vertices and edges, and fills two arrays
   // (distance and predecessor) with shortest-path
   // (less cost/distance/metric) information

   // Step 1: initialize graph
   for each vertex v in vertices:
       distance[v] := inf             // At the beginning , all vertices have a weight of infinity
       predecessor[v] := null         // And a null predecessor
   
   distance[source] := 0              // Except for the Source, where the Weight is zero 
   
   // Step 2: relax edges repeatedly
   for i from 1 to size(vertices)-1:
       for each edge (u, v) with weight w in edges:
           if distance[u] + w < distance[v]:
               distance[v] := distance[u] + w
               predecessor[v] := u

   // Step 3: check for negative-weight cycles
   for each edge (u, v) with weight w in edges:
       if distance[u] + w < distance[v]:
           error "Graph contains a negative-weight cycle"
   return distance[], predecessor[]