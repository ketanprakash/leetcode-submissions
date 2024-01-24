class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        if (sr < 0 || sr >= image.size() || sc < 0 || sc >= image[0].size()) return image;
        if (image[sr][sc] == color) return image;
        int n = image.size(); 
        int m = image[0].size();

        int startCol = image[sr][sc];
        image[sr][sc] = color; 
        queue<pair<int, int>> q; 
        q.push({sr, sc});

        vector<int> dx{0, 0, 1, -1};
        vector<int> dy{1, -1, 0, 0};

        int r, c, nx, ny;
        while (!q.empty()){
            r = q.front().first;
            c = q.front().second;
            q.pop();

            for (int i = 0; i < 4; i++){
                nx = r + dx[i]; ny = c + dy[i];

                if (nx < 0 || nx >= n || ny < 0 || ny >= m || image[nx][ny] != startCol) continue;
                image[nx][ny] = color;
                q.push({nx, ny});
            }
        }

        return image;
    }
};