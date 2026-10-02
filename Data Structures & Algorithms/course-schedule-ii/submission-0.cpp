class Solution {
public:

    bool dfs(int node, vector<vector<int>>& graph,
             vector<bool>& visited, vector<bool>& path,
             vector<int>& result) {

        visited[node] = true;
        path[node] = true;

        for (int neighbor : graph[node]) {

            if (path[neighbor]) return true;

            if (!visited[neighbor]) {
                if (dfs(neighbor, graph, visited, path, result))
                    return true;
            }
        }

        path[node] = false;
        result.push_back(node);

        return false;
    }

    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {

        vector<vector<int>> graph(numCourses);

        // Build adjacency list: prerequisite -> course
        for (auto& p : prerequisites) {
            int course = p[0];
            int prerequisite = p[1];

            graph[prerequisite].push_back(course);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);
        vector<int> result;

        // Explore every disconnected component
        for (int i = 0; i < numCourses; i++) {

            if (!visited[i]) {
                if (dfs(i, graph, visited, path, result)) {
                    return {};
                }
            }
        }

        // DFS finishing order is reversed
        reverse(result.begin(), result.end());

        return result;
    }
};