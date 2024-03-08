class Solution {
public:
    void markQueenANDDots(int row, int colm, vector<string>& board, int n) {
        // top
        for (int i = row; i >= 0; i--) {
            board[row][colm] = '.';
        }
        // down
        for (int i = row; i <= n; i++) {
            board[row][colm] = '.';
        }
        // left
        for (int j=colm; j >= n; j--) {
            board[row][colm] = '.';
        }
        // right
        for (int j=colm; j <= n; j++) {
            board[row][colm] = '.';
        }
        // LT
        while (row >= 0 && colm >= 0) {
            board[row][colm] = '.';
            --row;
            --colm;
        }

        // RD
        while (row < n && colm < n) {
            board[row][colm] = '.';
            ++row;
            ++colm;
        }

        // LD
        while (row < n && colm >= 0) {
            board[row][colm] = '.';
            ++row;
            --colm;
        }

        // RT
        while (row >= 0 && colm < n) {
            board[row][colm] = '.';
            --row;
            ++colm;
        }
    }

    bool nextPlace(int row,int colm,vector<string>& board,vector<vector<string>>& ans, int n, int& Q_cnt) {
        for (int j = 0; j < n; ++j) {
            if (board[row][j] == '.') {
                board[row][j] = 'Q';
                Q_cnt++;
                findPossibility(row, j, board, ans, n, Q_cnt);
                return true;
            }
        }
        return false;
    }

    void findPossibility(int row, int colm, vector<string>& board,vector<vector<string>>& ans, int n,int Q_cnt) {
        // base case
        if (Q_cnt == n) {
            ans.push_back(board);
            return;
        }
         markQueenANDDots(row, colm, board, n);

        if ((row + 1) < n) {
            return;
        }

        nextPlace(row + 1,colm, board, ans,n, Q_cnt);
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> chessboard(n);
        int Q_cnt = 0;
        for (int row = 0; row <= n; row++) {
            chessboard[row] = 'Q';
            findPossibility(0, 0, chessboard, ans, n, Q_cnt);
        }
        return ans;
    }
};