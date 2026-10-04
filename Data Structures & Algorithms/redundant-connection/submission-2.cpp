class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;

    bool dfs(int node ,int end) {
        visited[node] = true;

        if(node == end) return true;


        for (int neighbor : adj[node]) {
            if (!visited[neighbor]) {
                if(dfs(neighbor,end)) return true;
            }
        }

        return false;
    }


    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        
        int n = edges.size();

        adj.resize(n+1);
        visited.resize(n+1,false);

        // creating the adjacency list
        for(auto& edge : edges){
            
            visited.assign(n + 1, false);

            int u = edge[0];
            int v = edge[1];
            
            if(dfs(u,v)){
                return {u,v};
            }
            else{
                adj[u].push_back(v);
                adj[v].push_back(u);
            }
        }

        return {};
    }
};
