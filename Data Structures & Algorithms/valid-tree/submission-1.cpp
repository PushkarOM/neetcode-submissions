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
