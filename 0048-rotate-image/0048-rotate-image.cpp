//O(n2)
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        for(int i=0;i<n;i++){ //transpose of the matrix
            for(int j=i+1;j<n;j++){
                swap(matrix[i][j],matrix[j][i]);
            }
        }
        for(int i=0;i<n;i++){ //reversing rows
            reverse(matrix[i].begin(),matrix[i].end());
        }
    }
};