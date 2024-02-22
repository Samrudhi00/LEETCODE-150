class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        int low = 0;
        int high = rows * cols - 1;

        while (low <= high) {
            int mid = (low + high) / 2;
            int midValue = matrix[mid / cols][mid % cols];

            if (midValue == target) {
                return true;
            } else if (midValue < target) {
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }

        return false; // Target not found
        // int low_row = 0;
        // int low_colm = 0;
        // int high_row = m - 1;
        // int high_colm = m * n - 1;

        // while (low_row <= high_row && low_colm <= high_colm) {
        //     int mid_row = (low_row + high_row) / 2;
        //     int mid_colm = (low_colm + high_colm) / 2;
        //     int mid_value = matrix[mid_row][mid_colm];

        //     if (mid_value > target) {
        //         if (mid_colm - 1 < 0) {
        //             high_colm = n - 1;
        //             high_row = ((high_row - low_row) * n) + (n - 1);
        //         } else {
        //             high_colm = mid_colm - 1;
        //             high_row = mid_row;
        //         }
        //     } else if (mid_value < target) {
        //         if (mid_colm + 1 >= n) {
        //             low_row = mid_row + 1;
        //             low_colm = 0;
        //         } else {
        //             low_row = mid_row;
        //             low_colm = mid_colm + 1;
        //         }
        //     } else if (mid_value == target) {
        //         return true;
        //     }
        // }
        // return false;
    }
};
