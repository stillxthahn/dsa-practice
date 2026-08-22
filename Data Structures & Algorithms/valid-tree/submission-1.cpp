class Solution {
public:
    vector<vector<int>> adj;
    vector<int> visited;
    bool validTree(int n, vector<vector<int>>& edges) {
        adj = vector<vector<int>> (n, vector<int>());
        visited = vector<int>(n, 0);
        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int components = 0;
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) {
                if (!dfs(i, -1)) return false;
                components++;
            }
        }
        return components == 1;
    }

    bool dfs(int start, int parent) {
        if (visited[start] == 1) return false;

        visited[start] = 1;

        for (int &nei : adj[start]) {
            if (nei == parent) continue;
            if (visited[nei] == 1) {
                return false;
            }
            else if (visited[nei] == 0) {
                if (!dfs(nei, start)) return false;
            }
        }

        visited[start] = 2;
        return true;
    }


};
