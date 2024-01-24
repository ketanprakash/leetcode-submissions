class DisjointSet{
    public: 
    vector<int> parent, size;

    DisjointSet(int n){
        parent.resize(n);
        size.resize(n);

        for (int i = 0; i < n; i++) {
            size[i] = 1;
            parent[i] = i;
        }
    }

    int findParent(int node){
        if (node == parent[node]) return node;
        return parent[node] = findParent(parent[node]);
    }

    void unionBySize(int node1, int node2){
        int parent1 = findParent(node1);
        int parent2 = findParent(node2);
        
        if (parent1 == parent2) return;

        if (size[parent1] >= size[parent2]) {
            parent[parent2] = parent1;
            size[parent1] += size[parent2];
        }
        else {
            parent[parent1] = parent2;
            size[parent2] += size[parent1];
        }
    }
};

class Solution {
public:
    int largestIsland(vector<vector<int>>& grid) {
        int n = grid.size(); 
        DisjointSet ds(n * n);
        bool allOnes = true;
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                if (grid[i][j] == 0) {
                    allOnes = false;
                    continue;
                }

                int num = i * n + j;
                //add right
                if (j + 1 < n && grid[i][j + 1]) ds.unionBySize(num, num + 1);
                if (i + 1 < n && grid[i + 1][j]) ds.unionBySize(num, num + n);
            }
        }

        if (allOnes) return n * n;

        unordered_set<int> s;

        int dx[] = {-1, 1, 0, 0};
        int dy[] = {0, 0, -1, 1};

        int maxSize = 0; 
        for (int i = 0; i < n; i++){
            for (int j = 0; j < n; j++){
                s = unordered_set<int>();
                int islandSize = 1;
                if (grid[i][j] == 0){
                    for (int x = 0; x < 4; x++){
                        int nx = i + dx[x];
                        int ny = j + dy[x];
                        
                        if (nx < 0 || ny < 0 || nx >= n || ny >= n || grid[nx][ny] == 0 || s.find(ds.findParent(nx * n + ny)) != s.end()) continue;
                        s.insert(ds.findParent(nx * n + ny));
                        islandSize += ds.size[ds.findParent(nx * n + ny)];
                    }
                    maxSize = max(maxSize, islandSize);
                }
            }
        }
        return maxSize;
    }
};