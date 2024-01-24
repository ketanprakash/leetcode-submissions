class Solution:
    def rotate(self, a: List[List[int]]) -> None:
        s, e = 0, len(a) - 1
        
        while s <= e:
            for i in range(s, e):
                a[s][i], a[i][e], a[e][-i - 1], a[-i - 1][s] = a[-i - 1][s], a[s][i], a[i][e], a[e][-i - 1]
            s, e = s + 1, e - 1