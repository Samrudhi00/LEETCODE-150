#include <vector>
#include <algorithm> // for std::max

using namespace std;

class Solution {
public:
    int checkForAllDirections(int i, int j, int maximum_gold, int maximum_path, vector<vector<int>>& grid, int m, int n) {
        if (i < 0 || j < 0 || i >= m || j >= n) return maximum_path;
        
        // Save the value of the current cell and mark it as visited
        int current_value = grid[i][j];
        grid[i][j] = 0;
        
        int localmax=0;
        // Calculate maximum path by exploring all directions
        int p=0,q=0;
        int left = gird[i][j-1];
        if(i >=m || j >=n)
         int right = grid[i][j+1];
        int up = gir
        int left = checkForAllDirections(i, j - 1, maximum_gold, maximum_path + current_value, grid, m, n);
        int right = checkForAllDirections(i, j + 1, maximum_gold, maximum_path + current_value, grid, m, n);
        int up = checkForAllDirections(i - 1, j, maximum_gold, maximum_path + current_value, grid, m, n);
        int down = checkForAllDirections(i + 1, j, maximum_gold, maximum_path + current_value, grid, m, n);
        
        // Restore the original value of the current cell (backtracking)
        grid[i][j] = current_value;
        
        // Return the maximum path
        return max({left, right, up, down});
    }
    
    int getMaximumGold(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        int maximum_gold = 0;

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                // Start exploring from each cell
                maximum_gold = max(maximum_gold, checkForAllDirections(i, j, 0, 0, grid, m, n));
            }
        }
        return maximum_gold;
    }
};
