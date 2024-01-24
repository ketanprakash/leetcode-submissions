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
        return findParent(parent[node]);
    }

    void unionBySize(int node1, int node2){
        int parent1 = findParent(node1);
        int parent2 = findParent(node2);

        parent[parent2] = parent1;
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet ds(n);
        for (int i = 0; i < connections.size(); i++){
            ds.unionBySize(connections[i][0], connections[i][1]);
        }

        int countComponents = 0;

        for (int i = 0; i < n; i++){
            if (ds.findParent(i) == i) countComponents++;
        }

        return connections.size() < n - 1 ? -1 : countComponents - 1;
    }
};