class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int rows = matrix.size();
        int cols = matrix[0].size();

        bool firstRowZero = false;
        bool firstColZero = false;

        // Step 1: Check if first row has zero
        for (int c = 0; c < cols; c++) {
            if (matrix[0][c] == 0) {
                firstRowZero = true;
                break;
            }
        }

        // Step 2: Check if first column has zero
        for (int r = 0; r < rows; r++) {
            if (matrix[r][0] == 0) {
                firstColZero = true;
                break;
            }
        }

        // Step 3: Use first row/col as markers
        for (int r = 1; r < rows; r++) {
            for (int c = 1; c < cols; c++) {
                if (matrix[r][c] == 0) {
                    matrix[r][0] = 0;
                    matrix[0][c] = 0;
                }
            }
        }

        // Step 4: Set zeros based on markers (rows)
        for (int r = 1; r < rows; r++) {
            if (matrix[r][0] == 0) {
                for (int c = 1; c < cols; c++) {
                    matrix[r][c] = 0;
                }
            }
        }

        // Step 5: Set zeros based on markers (columns)
        for (int c = 1; c < cols; c++) {
            if (matrix[0][c] == 0) {
                for (int r = 1; r < rows; r++) {
                    matrix[r][c] = 0;
                }
            }
        }

        // Step 6: Fix first row
        if (firstRowZero) {
            for (int c = 0; c < cols; c++) {
                matrix[0][c] = 0;
            }
        }

        // Step 7: Fix first column
        if (firstColZero) {
            for (int r = 0; r < rows; r++) {
                matrix[r][0] = 0;
            }
        }
    }
};