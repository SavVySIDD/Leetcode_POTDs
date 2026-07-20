class Solution {
public:

    void reverse(vector<vector<int>>& grid, int left, int right, int cols) {

        while(left < right) {

            int r1 = left / cols;
            int c1 = left % cols;

            int r2 = right / cols;
            int c2 = right % cols;

            swap(grid[r1][c1], grid[r2][c2]);

            left++;
            right--;
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int rows = grid.size();
        int cols = grid[0].size();

        int total = rows * cols;
        k %= total;

        reverse(grid, 0, total - 1, cols);
        reverse(grid, 0, k - 1, cols);
        reverse(grid, k, total - 1, cols);

        return grid;
    }
};