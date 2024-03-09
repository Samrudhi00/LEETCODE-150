class Solution {
public:
    bool CanPlaceQueen(int row, int colm, vector<string>& board, int n) {
        // Check vertically
        // for (int i = 0; i < n; ++i) {
        //     if (i != row && board[i][colm] == 'Q') {
        //         return false;
        //     }
        // }

        // Check diagonally
        int r, c;

        // Top
        r = row - 1;
        c = colm;
        while (r >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            --r;
        }

        // Down
        r = row + 1;
        while (r < n) {
            if (board[r][colm] == 'Q') {
                return false;
            }
            ++r;
        }

        // Left
        r = row;
        c = colm - 1;
        while (c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            --c;
        }

        // Right
        c = colm + 1;
        while (c < n) {
            if (board[row][c] == 'Q') {
                return false;
            }
            ++c;
        }

        // Diagonals (LT, RD, LD, RT)
        r = row - 1;
        c = colm - 1;
        while (r >= 0 && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            --r;
            --c;
        }

        r = row + 1;
        c = colm + 1;
        while (r < n && c < n) {
            if (board[r][c] == 'Q') {
                return false;
            }
            ++r;
            ++c;
        }

        r = row + 1;
        c = colm - 1;
        while (r < n && c >= 0) {
            if (board[r][c] == 'Q') {
                return false;
            }
            ++r;
            --c;
        }

        r = row - 1;
        c = colm + 1;
        while (r >= 0 && c < n) {
            if (board[r][c] == 'Q') {
                return false;
            }
            --r;
            ++c;
        }

        return true;
    }

    void addSolution(vector<vector<string>>& ans, const vector<string>& board) {
        ans.push_back(board);
    }

    void findPossibility(int colm, vector<vector<string>>& ans,
                         vector<string>& board, int n) {
        // Base case
        if (colm == n) {
            addSolution(ans, board);
            return;
        }

        for (int row = 0; row < n; ++row) {
            // Can we place the queen
            if (CanPlaceQueen(row, colm, board, n)) {
                // If yes
                board[row][colm] = 'Q';
                // Recursion
                findPossibility(colm + 1, ans, board, n);
                // Backtracking
                board[row][colm] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        vector<vector<string>> ans;
        findPossibility(0, ans, board, n);
        return ans;
    }
};
