class Solution {
public:
    int explorePaths(int i, int j, vector<vector<int>>& grid) {
        
        int m = grid.size();
        int n = grid[0].size();
        // bc
        if (i < 0 || j < 0 || i >= m || j >= n || grid[i][j] == 0)
            return 0;
        
        ////add new gold
        int currentGold = grid[i][j]; 
        //mark visited
        grid[i][j] = 0; 

        // left , right , up , down
        int maxGold = currentGold + max({explorePaths(i + 1, j, grid),
                                         explorePaths(i - 1, j, grid),
                                         explorePaths(i, j + 1, grid),
                                         explorePaths(i, j - 1, grid)});

        //restore 0=>6
        grid[i][j] = currentGold; 

        return maxGold;
    }

    int getMaximumGold(vector<vector<int>>& grid) {
        
        int maxGold = 0;

        for (int i = 0; i < grid.size(); ++i) {
            for (int j = 0; j < grid[0].size(); ++j) {
                if (grid[i][j] != 0) { 
                    
                    maxGold = max(maxGold, explorePaths(i, j, grid));
                }
            }
        }

        return maxGold;
    }
};
