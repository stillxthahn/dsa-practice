class Solution {
public:
    int m, n;
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    vector<vector<bool>> visitedPacific, visitedAtlantic;
    vector<vector<int>> pacificAtlantic(vector<vector<int>>& heights) {
        m = heights.size(), n = heights[0].size();
        visitedPacific = vector<vector<bool>>(m, vector<bool>(n, false));
        visitedAtlantic = vector<vector<bool>>(m, vector<bool>(n, false));

        queue<pair<int, int>> qPacific, qAtlantic;
        for (int j = 0; j < n; j++) {
            qPacific.push({0, j});
            visitedPacific[0][j] = true;

            qAtlantic.push({m - 1, j});
            visitedAtlantic[m - 1][j] = true;
        }

        for (int i = 0; i < m; i++) {
            qPacific.push({i, 0});
            visitedPacific[i][0] = true;

            qAtlantic.push({i, n - 1});
            visitedAtlantic[i][n - 1] = true;
        }

        bfs(heights, visitedPacific, qPacific);
        bfs(heights, visitedAtlantic, qAtlantic);

        vector<vector<int>> res;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (visitedPacific[i][j] && visitedAtlantic[i][j]) {
                    res.push_back({i, j});
                }
            }
        }
        return res;
    }

    void bfs(vector<vector<int>>& heights, vector<vector<bool>> &visited, queue<pair<int, int>> &q) {
        while (q.size()) {
            auto [x, y] = q.front();
            q.pop();

            for (int k = 0; k < 4; k++) {
                int du = x + dx[k];
                int dv = y + dy[k];

                if (du < 0 || dv < 0 || du >= m || dv >= n || visited[du][dv] || heights[du][dv] < heights[x][y]) continue;
                visited[du][dv] = true;
                q.push({ du, dv });
            }
        }
    }
};