class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;

    void dfs(int node) {
        visited[node] = true;

        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                dfs(neighbor);
            }
        }
    }

    int countComponents(int n, vector<vector<int>>& edges) {

        adj.resize(n);
        visited.resize(n,false);

        // creating the adjacency list
        for(auto& edge : edges){
        
            int u = edge[0];
            int v = edge[1];

            adj[u].push_back(v);
            adj[v].push_back(u);
        
        }
        
        int components = 0;
        //call dfs from every 
        for(int i = 0 ; i < n; i++){
            if (!visited[i]) { // if this is not visited, it's a new start/component
                dfs(i);
                components++;
            }
        }

        return components;
    }
};

 /*
    We want to count how many disconnected components exist in the graph.

    Think of each connected component as an "island" of nodes:
        - Starting DFS from any node explores the ENTIRE island/component.
        - Therefore, we only need to start DFS when we find an unvisited node.
        - If a node is already visited, its component was already explored
          by an earlier DFS, so we do not count it again.

    Example:

        0 -- 1 -- 2        3 -- 4        5

        DFS from 0 -> visits {0,1,2} -> 1 component
        Nodes 1 and 2 are already visited, so skip them.

        DFS from 3 -> visits {3,4}   -> 1 new component
        Node 4 is already visited, so skip it.

        DFS from 5 -> visits {5}     -> 1 new component

        Total = 3 components.

    The important idea:
        "An unvisited node means we have discovered a NEW component."

    So:
        if (!visited[i]) {
            dfs(i);          // explore the entire component
            components++;    // count it exactly once
        }

    DFS itself only marks all reachable nodes. The outer loop is what
    discovers and counts the separate components.
 */