class Solution {
public:
    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    int m, n;
    bool exist(vector<vector<char>>& board, string word) {
        m = board.size();
        n = board[0].size();

        vector<vector<bool>> visited(m, vector<bool>(n, false));

        unordered_map<char, int> mp;
        for (char c : word) mp[c] = 1;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == word[0]) {
                    // output.push_back(word[0]);

                    visited = vector<vector<bool>>(m, vector<bool>(n, false));
                    visited[i][j] = true;

                    bool check = backtracking(board, i, j, 1, visited, word);
                    if (check) return true;
                }
            }
        }
        return false;
    }

    bool backtracking(vector<vector<char>>& board, int i, int j, int idx, vector<vector<bool>> &visited, string &word) {
        if (idx == word.length()) return true;

        for (int k = 0; k < 4; k++) {
            int du = i + dx[k];
            int dv = j + dy[k];
            if (du < 0 || dv < 0 || du >= m || dv >= n || visited[du][dv]) continue;

            if (board[du][dv] == word[idx]) {
                // output.push_back(board[du][dv]);
                visited[du][dv] = true;
                if (backtracking(board, du, dv, idx + 1, visited, word)) return true;
                // output.pop_back();
                visited[du][dv] = false;
            }
        }
        return false;
    }
};
