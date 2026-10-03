class Solution {
public:

    vector<vector<int>> adj;
    vector<bool> visited;


    bool dfs(int node, int parent){
        visited[node] = true;

        for(int neighbour : adj[node]){

            // Ignore the edge we used to reach this node, i.e parent node
            if(neighbour == parent) continue;

            // already visited i.e cycle detected
            if(visited[neighbour]) return false;

            if(!dfs(neighbour, node)) return false;
        }

        return true;
    }

    bool validTree(int n, vector<vector<int>>& edges) {
        
        adj.resize(n);
        visited.resize(n,false);

        // Building the adjacency matric for the undirected graph
        for(auto& edge : edges){

            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u); // as this is an undirected graph
            
        }

        // start dfs from any node (here 0th node, this will be false if cycle detected)
        if(!dfs(0,-1)) return false;

        // if tree is connected (meaning not 2 or n independent component)
        for(bool x : visited){
            if(!x) return false;
        }

        return true;

    }
};


/*
    A valid tree must satisfy two conditions:

    1. It must have NO CYCLE.
       During DFS, if we reach an already-visited neighbor that is not
       the parent we came from, there is another path to that node,
       which means a cycle exists.

    2. It must be CONNECTED.
       DFS starts from any node (we use node 0) and marks every node
       it can reach. After DFS, if any node is still unvisited, that
       node belongs to a separate component, so the graph is "broken"
       / disconnected and cannot be a tree.

    DFS therefore answers:
        "Starting from node 0, can I reach every node without finding a cycle?"

    For an undirected graph, we pass the parent node in DFS because when
    we go 0 -> 1, node 1 will naturally see 0 as a neighbor again.
    That edge is not a cycle; it is simply the edge we came from.

    Overall:
        - cycle found       -> false
        - some node unvisited -> false
        - otherwise          -> true
*/
