class Solution {
public:
    vector<vector<int>> adj;
    vector<bool> visited;
    int countComponents(int n, vector<vector<int>>& edges) {
        adj = vector<vector<int>>(n, vector<int>());
        visited = vector<bool>(n, false);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }

        int res = 0;
        for (int i = 0; i < n; i++) {
            if (!visited[i]) {
                // dfs(i);
                bfs(i);
                res++;
            }
        }
        return res;
    }

    void dfs(int start) {
        visited[start] = true;

        for (auto &nei : adj[start]) {
            if (visited[nei]) continue;
            dfs(nei);
        }
    }

    void bfs(int start) {
        queue<int> q;
        q.push(start);
        visited[start] = true;
        while (q.size()) {
            int x = q.front();
            q.pop();

            for (auto &nei : adj[x]) {
                if (visited[nei]) continue;
                visited[nei] = true;
                q.push(nei);
            }
        }
    }
};
