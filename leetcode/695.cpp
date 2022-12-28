class Solution {
  public:
    int maxAreaOfIsland(vector<vector<int>> &grid) {
        struct UnionFind {
            std::vector<int> parent, siz;

            // initialize
            UnionFind(int n) : parent(n, -1), siz(n, 1) {
            }

            int root(int x) {
                if (parent[x] == -1)
                    return x;
                else
                    return parent[x] = root(parent[x]);
            }

            int find(int x, int y) {
                return root(x) == root(y);
            }

            bool unite(int x, int y) {
                x = root(x);
                y = root(y);
                if (x == y)
                    return false;
                if (siz[x] < siz[y])
                    std::swap(x, y);
                parent[y] = x;
                siz[x] += siz[y];
                return true;
            }

            int size(int x) {
                return siz[root(x)];
            }
        };
        int m = grid.size();
        int n = grid[0].size();
        int result = 0;
        int noIsland = 1;
        UnionFind uf(m * n);
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 1) {
                    noIsland = 0;
                    if (i > 0 && grid[i - 1][j] == 1)
                        uf.unite(i * n + j, (i - 1) * n + j);
                    if (j > 0 && grid[i][j - 1] == 1)
                        uf.unite(i * n + j, i * n + j - 1);
                    if (i < m - 1 && grid[i + 1][j] == 1)
                        uf.unite(i * n + j, (i + 1) * n + j);
                    if (j < n - 1 && grid[i][j + 1] == 1)
                        uf.unite(i * n + j, i * n + j + 1);
                }
            }
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                result = max(result, uf.size(i * n + j));
            }
        }
        if (noIsland)
            return 0;
        return result;
    }
};
