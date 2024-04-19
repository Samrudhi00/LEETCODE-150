class Solution {
public:
    void visited_island(vector<vector<char>>& grid, int i, int j, int row, int colm) {
       if (i < 0 || i >= row || j < 0 || j >= colm || grid[i][j] != '1') {
            return;
       }
       grid[i][j] = '2';
       // Recur Call
       visited_island(grid, i + 1, j, row, colm);
       visited_island(grid, i - 1, j, row, colm);
       visited_island(grid, i, j + 1, row, colm);
       visited_island(grid, i, j - 1, row, colm);
    }

    int numIslands(vector<vector<char>>& grid) {
        int row = grid.size();
        if (row == 0) return 0;
        int colm = grid[0].size(); 
        int ans = 0;
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < colm; j++) {
                if (grid[i][j] == '1') {
                    visited_island(grid, i, j, row, colm);
                    ans += 1;
                }
            }
        }
        return ans;
    }
};
