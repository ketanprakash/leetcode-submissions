class Solution {
public:
class DisjointSet{
    public: 
    vector<int> parent;

    DisjointSet(int n){
        parent.resize(n + 1);

        for (int i = 1; i <= n; i++) {
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

        parent[parent2] = parent1;
    }
};

    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0, maxCol = 0;
        for (int i = 0; i < stones.size(); i++){
            maxRow = max(maxRow, stones[i][0]);
            maxCol = max(maxCol, stones[i][1]);
        }
        int n = maxRow + 1; 
        int m = maxCol + 1;
        DisjointSet ds(n + m);
        unordered_set<int> hasStones;

        for (int i = 0; i < stones.size(); i++){
            hasStones.insert(stones[i][0]);
            hasStones.insert(stones[i][1] + n);

            ds.unionBySize(stones[i][0], stones[i][1] + n);
        }

        int count = 0;

        for (int i = 0; i < n + m; i++){
            if (hasStones.find(i) != hasStones.end() && ds.findParent(i) == i) count++;
        }

        return stones.size() - count;
    }
};