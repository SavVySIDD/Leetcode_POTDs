class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();
        int leftSum=0, count=0, rightSum=0, maxSum=0;
        int right=n-1;
        for(int i=0;i<k;i++){
            leftSum += cardPoints[i];
            maxSum = leftSum;
        }
        for(int i=k-1;i>=0;i--){
            leftSum -= cardPoints[i];
            rightSum += cardPoints[right];
            right--;
            maxSum = max(maxSum, rightSum+leftSum);
        }
        return maxSum;
    }
};