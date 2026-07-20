class Solution {
public:

    void reverse(vector<int> &arr, int left, int right){
        while(left < right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }

    vector<vector<int>> shiftGrid(vector<vector<int>>& grid, int k) {

        int m = grid.size();
        int n = grid[0].size();

        vector<int> arr;

        // Flatten the grid
        for(auto &row : grid){
            for(auto &x : row){
                arr.push_back(x);
            }
        }

        int size = arr.size();
        k %= size;

        // Right rotate by k
        reverse(arr, 0, size - 1);
        reverse(arr, 0, k - 1);
        reverse(arr, k, size - 1);

        // Put elements back into grid
        int idx = 0;
        for(int i = 0; i < m; i++){
            for(int j = 0; j < n; j++){
                grid[i][j] = arr[idx++];
            }
        }

        return grid;
    }
};