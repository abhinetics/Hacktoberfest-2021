/*
You are given an m x n grid where each cell can have one of three values:

0 representing an empty cell,
1 representing a fresh orange, or
2 representing a rotten orange.
Every minute, any fresh orange that is 4-directionally adjacent to a rotten orange becomes rotten.

Return the minimum number of minutes that must elapse until no cell has a fresh orange. If this is impossible, return -1.


Example 1:
https://assets.leetcode.com/uploads/2019/02/16/oranges.png

Input: grid = [[2,1,1],[1,1,0],[0,1,1]]
Output: 4
Example 2:

Input: grid = [[2,1,1],[0,1,1],[1,0,1]]
Output: -1
Explanation: The orange in the bottom left corner (row 2, column 0) is never rotten, because rotting only happens 4-directionally.
Example 3:

Input: grid = [[0,2]]
Output: 0
Explanation: Since there are already no fresh oranges at minute 0, the answer is just 0.
 

Constraints:

m == grid.length
n == grid[i].length
1 <= m, n <= 10
grid[i][j] is 0, 1, or 2.
*/

class Solution {
public:
    void checkNeighbour(queue<pair<int,int>> &q, vector<vector<int>> &grid, pair<int,int> curr){
        
        // Left Right Up Down
        int x[] = {-1,1,0,0};
        int y[] = {0,0,-1,1};
        
        for(int i=0;i<4;i++){
                int Xcord = curr.first+x[i];
                int Ycord = curr.second+y[i];
                if(Xcord<0 || Xcord>=grid.size()
                || Ycord<0 || Ycord>=grid[0].size()
                || grid[Xcord][Ycord]!=1){
                    continue;
                }        
            grid[Xcord][Ycord] = 2;
            q.push({Xcord,Ycord});
        }
    }
    
    int orangesRotting(vector<vector<int>>& grid) {
        queue<pair<int,int>> q;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j] == 2){
                    q.push({i,j});
                }
            }
        }
        
        int time = 0;
        
        while(q.size()>0){
            int count = q.size();
            while(count>0){
                pair<int,int> top = q.front();
                q.pop();
                checkNeighbour(q,grid,top);
                count--;
            }
            time++;
        }
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                if(grid[i][j] == 1){
                    return -1;
                }
            }
        }
        if(time>0)
            return time-1;
        
        return time;
    }
};
