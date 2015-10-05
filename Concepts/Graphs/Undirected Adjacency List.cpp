set<int>::const_iterator pos;

class UndirectedGraph
{
    private:
        int num_nodes = 0;
        vector<set<int>> adjacency_list;
    public:
        UndirectedGraph(int num_nodes) {
            adjacency_list.resize(num_nodes);
        }
        void add_neighbour(int vertex, int neighbour) { 
            adjacency_list[vertex].insert(neighbour);
        };
        void print_graph() {
            for(int i = 0; i < num_nodes; i++) {
                for(pos = adjacency_list[i].begin(); pos != adjacency_list[i].end(); ++pos) {
                    cout<<*pos<<' ';
                }
            }
        }
 };