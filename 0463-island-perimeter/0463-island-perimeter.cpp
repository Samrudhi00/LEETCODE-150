class Solution {
public:
    // up      i-1   j
    // down    i+1   j
    // left    i     j-1
    // right   i     j+1
    int islandPerimeter(vector<vector<int>>& grid) {
        int perimeter = 0;
        int row = grid.size();
        if (row == 0)
            return 0; // Check if the grid is empty else giving runtime error
        int col = grid[0].size();
        for (int i = 0; i < row; i++) {
            for (int j = 0; j < col; j++) {
                if (grid[i][j] == 1) {
                    perimeter += 4;
                    if (i > 0 && grid[i - 1][j] == 1) {
                        perimeter--;
                    }
                    if (i < row - 1 && grid[i + 1][j] == 1) {
                        perimeter--;
                    }
                    if (j > 0 && grid[i][j - 1] == 1) {
                        perimeter--;
                    }
                    if (j < col - 1 && grid[i][j + 1] == 1) {
                        perimeter--;
                    }
                }
            }
        }
        return perimeter;
    }
};