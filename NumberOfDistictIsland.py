import sys
from typing import List
class Solution:
    sys.setrecursionlimit(10**8)
    def countDistinctIslands(self, grid : List[List[int]]) -> int:
        track = []
        ROW,COL = len(grid),len(grid[0])
        
        def isValid(r,c):
            return (r >=0 and
            c >= 0 and
            r < ROW and
            c < COL and
            grid[r][c] == 1)
        
        def dfs(r,c,i,j):
            if not isValid(r,c):
                return 
            a.append((i,j))
            grid[r][c] = 2
            dfs(r+1, c, i+1,j)
            dfs(r-1, c, i-1,j)
            dfs(r, c-1, i,j-1)
            dfs(r, c+1, i,j+1)
            
        for r in range(ROW):
            for c in range(COL):
                if grid[r][c] == 1:
                    a = []
                    dfs(r,c, 0,0)
                    track.append(tuple(a))
        return len(set(tuple(track)))
