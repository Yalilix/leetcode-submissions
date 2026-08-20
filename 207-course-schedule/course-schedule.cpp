class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        int n = prerequisites.size();
        vector<vector<int>> graph(numCourses);
        for (int i = 0; i < n; i++) {
            int s = prerequisites[i][0];
            int e = prerequisites[i][1];

            graph[s].push_back(e);
        }

        set<int> visiting;
        set<int> visited;

        for (int i = 0; i < numCourses; i++) {
            if (!visited.contains(i)) {
                if (!dfs(i, graph, visiting, visited)) return false;
            }
        }

        return true;
    }

private:
    bool dfs(int node, vector<vector<int>>& graph, set<int>& visiting, set<int>& visited) {
        if (visiting.contains(node)) return false;
        
        if (visited.contains(node)) return true;

        visiting.insert(node);

        for (auto nei : graph[node]) {
            bool cur = dfs(nei, graph, visiting, visited);
            if (!cur) return false;
        }

        visiting.erase(node);
        visited.insert(node);


        return true;
    }
};