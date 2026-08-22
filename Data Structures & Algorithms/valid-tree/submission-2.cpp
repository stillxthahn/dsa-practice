class Solution {
public:
    vector<vector<int>> adj;
    vector<int> visited;
    bool validTree(int n, vector<vector<int>>& edges) {
        adj = vector<vector<int>>(n, vector<int>());
        visited = vector<int>(n, 0);

        for (auto &e : edges) {
            adj[e[0]].push_back(e[1]);
            adj[e[1]].push_back(e[0]);
        }
        queue<pair<int, int>> q;
        q.push({ 0, -1 });
        visited[0] = 1;

        while (q.size()) {
            auto [x, parent] = q.front();
            q.pop();

            for (int &nei : adj[x]) {
                if (nei == x) continue;
                if (visited[nei] == 1) return false;
                if (visited[nei] == 0) {
                    visited[nei] = 1;
                    q.push({ nei, x });
                }
            }
            visited[x] = 2;
        }
        
        for (int i = 0; i < n; i++) {
            if (visited[i] == 0) return false;
        }
        return true;
    }
};
