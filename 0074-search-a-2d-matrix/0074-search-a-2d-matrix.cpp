class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int rows = matrix.size();
        int cols = matrix[0].size();
        int low =0, high = rows*cols-1;
        while(low<=high){
            int mid = (low+high)/2;
            int lowEle = matrix[low/cols][low%cols];
            int highEle = matrix[high/cols][high%cols];
            int currEle = matrix[mid/cols][mid%cols];
            if (currEle== target) return true;
            if(lowEle<= target && target< currEle){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }
        return false;
    }
};