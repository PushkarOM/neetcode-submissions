class Solution {
public:

    bool dfs(
        int course,
        vector<vector<int>>& graph,
        vector<bool>& visited,
        vector<bool>& path
    ) {
        // Mark this course as visited
        // and add it to the current DFS path
        visited[course] = true;
        path[course] = true;

        for (int nextCourse : graph[course]) {

            // If this course is already in our
            // current DFS path, we found a cycle
            if (path[nextCourse]) {
                return true;
            }

            // Only explore courses we haven't visited yet
            if (!visited[nextCourse]) {
                if (dfs(nextCourse, graph, visited, path)) {
                    return true;
                }
            }
        }

        // We are done exploring this course.
        // Remove it from the current DFS path.
        path[course] = false;

        return false;
    }

    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {

        // Build adjacency list
        vector<vector<int>> graph(numCourses);

        for (auto& prerequisite : prerequisites) {
            int course = prerequisite[0];
            int prerequisiteCourse = prerequisite[1];

            graph[prerequisiteCourse].push_back(course);
        }

        vector<bool> visited(numCourses, false);
        vector<bool> path(numCourses, false);

        // There can be multiple disconnected components,
        // so start DFS from every unvisited course.
        for (int course = 0; course < numCourses; course++) {

            if (!visited[course]) {
                if (dfs(course, graph, visited, path)) {
                    return false;  // cycle exists
                }
            }
        }

        return true;  // no cycle
    }
};