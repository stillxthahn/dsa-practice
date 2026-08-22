class UnionFind {
public:
    vector<int> pa;
    int components = 0;
    UnionFind(int n) {
        pa = vector<int>(n, 0);
        for (int i = 0; i < n; i++) pa[i] = i;
        components = n;
    }

    int find(int x) {
        if (pa[x] != x) pa[x] = find(pa[x]);
        return pa[x];
    }

    bool unite(int x, int y) {
        int px = find(x);
        int py = find(y);
        if (px == py) return false;
        pa[py] = px;
        components--;
        return true;
    }
};

class Solution {
public:
    bool validTree(int n, vector<vector<int>>& edges) {
        UnionFind uf(n);
        for (auto &e : edges) {
            if (!uf.unite(e[0], e[1])) return false;
        }
        return uf.components == 1;
    }
};
