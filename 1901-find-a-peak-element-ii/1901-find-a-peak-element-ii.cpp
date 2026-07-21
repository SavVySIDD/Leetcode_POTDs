class Solution {
    int find(vector<vector<int>>&mat, int mid){
        int maxi = -1;
        int ind = -1;
        for(int i=0;i<mat.size();i++){
            if(mat[i][mid]>maxi){
                maxi = mat[i][mid];
                ind = i;
            }
        }
        return ind;
    }
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int n = mat.size(), m = mat[0].size();
        int lowCol = 0, highCol = m-1;
        while(lowCol<=highCol){
            int mid = lowCol + (highCol-lowCol)/2;
            int maxRow = find(mat,mid);
            int left = (mid == 0) ? -1 : mat[maxRow][mid - 1];
            int right = (mid == m - 1) ? -1 : mat[maxRow][mid + 1];
            int currEle = mat[maxRow][mid];
            if(currEle>left && currEle>right){
                return {maxRow,mid};
            }
            else if(currEle>left){
                lowCol = mid+1;
            }
            else{
                highCol =mid-1;
            }
        }
        return {-2,-1};
    }
};