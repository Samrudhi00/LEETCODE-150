class Solution {
public:
    bool helper(int i, int j, int m, int n, vector<vector<char>>& board,
                int index, string word) {
        if (word.size() == index)
            return true;
        if (i < 0 || j < 0 || i >= m || j >= n || board[i][j] != word[index])
            return false;

        if (word[index] == board[i][j]) {
            char ch = board[i][j]; 
            board[i][j] = '-'; 
            bool found = helper(i, j - 1, m, n, board, index + 1, word) ||
                         helper(i, j + 1, m, n, board, index + 1, word) ||
                         helper(i - 1, j, m, n, board, index + 1, word) ||
                         helper(i + 1, j, m, n, board, index + 1, word);
            if (!found)
                board[i][j] = ch; 
            return found;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size();
        int n = board[0].size();
        //if(m * n < word.size())return false;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
               
                // if (word[0] == board[i][j]) {
                     if (helper(i, j, m, n, board, 0, word))
                       return true;
                // }
            }
        }
        return false;
    }
};
