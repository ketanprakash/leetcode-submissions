/*
// Definition for a QuadTree node.
class Node {
public:
    bool val;
    bool isLeaf;
    Node* topLeft;
    Node* topRight;
    Node* bottomLeft;
    Node* bottomRight;
    
    Node() {
        val = false;
        isLeaf = false;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = NULL;
        topRight = NULL;
        bottomLeft = NULL;
        bottomRight = NULL;
    }
    
    Node(bool _val, bool _isLeaf, Node* _topLeft, Node* _topRight, Node* _bottomLeft, Node* _bottomRight) {
        val = _val;
        isLeaf = _isLeaf;
        topLeft = _topLeft;
        topRight = _topRight;
        bottomLeft = _bottomLeft;
        bottomRight = _bottomRight;
    }
};
*/

class Solution {
public:
    Node* helper(vector<vector<int>> &grid, int sr, int er, int sc, int ec){
        if (sr == er && sc == ec){
            return new Node(grid[sr][sc], true);
        }
        int val = grid[sr][sc];
        bool flag = true;
        for (int i = sr; i <= er; i++){
            for (int j = sc; j <= ec; j++){
                if (val != grid[i][j]) {
                    flag = false; 
                    break;
                }
            }
        }

        if (flag){
            return new Node(val, true);
        }
        
        int mr = sr + (er - sr) / 2;
        int mc = sc + (ec - sc) / 2;

        Node *root = new Node(0, false);
        root -> topLeft = helper(grid, sr, mr, sc, mc);
        root -> topRight = helper(grid, sr, mr, mc + 1, ec);
        root -> bottomLeft = helper(grid, mr + 1, er, sc, mc);
        root -> bottomRight = helper(grid, mr + 1, er, mc + 1, ec);

        return root;
    }

    Node* construct(vector<vector<int>>& grid) {
        return helper(grid, 0, grid.size() - 1, 0, grid[0].size() - 1);
    }
};