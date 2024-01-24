class Solution {
public:
    int minMovesToCaptureTheQueen(int a, int b, int c, int d, int e, int f) {
        //end with bishop
        if (c + d == e + f) {
            if (a + b != c + d) return 1;
            if (a - b < min(c - d, e - f) || a - b > max(c - d, e - f)) return 1;
        }
        if (c - d == e - f) {
            if (a - b != c - d) return 1;
            if (a + b < min(c + d, e + f) || a + b > max(c + d, e + f)) return 1;
        }
        
        //end with rook
        if (a == e) {
            if (c != a) return 1;
            if (d < min(b, f) || d > max(b, f)) return 1;
        }
        
        if (b == f) {
            if (d != b) return 1;
            if (c < min(a, e) || c > max(a, e)) return 1;
        }
        
        return 2;
    }
};