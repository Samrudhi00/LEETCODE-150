class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> result;
        int top = 0;
        int bottom = matrix.size() - 1;
        int left = 0;
        int right = matrix[0].size() - 1;
        int dir = 0;

        while (top <= bottom && left <= right) {
            switch (dir) {
                case 0: // Right
                    for (int i = left; i <= right; i++) {
                        result.push_back(matrix[top][i]);
                    }
                    top++;
                    break;
                case 1: // Down
                    for (int i = top; i <= bottom; i++) {
                        result.push_back(matrix[i][right]);
                    }
                    right--;
                    break;
                case 2: // Left
                    for (int i = right; i >= left; i--) {
                        result.push_back(matrix[bottom][i]);
                    }
                    bottom--;
                    break;
                case 3: // Top
                    for (int i = bottom; i >= top; i--) {
                        result.push_back(matrix[i][left]);
                    }
                    left++;
                    break;
            }
            dir = (dir + 1) % 4;
        }

        return result;
    }
};