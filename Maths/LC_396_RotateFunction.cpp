//First I solve myself using this Brute Force for which I obviously got TLE as it is O(n^2)

// class Solution {
// public:
//     int maxRotateFunction(vector<int>& nums) {
//         int n = nums.size();
//         int res = INT_MIN;
//         for(int i=0;i<n;i++){
//             int count = 0;
//             int j=i;
//             int temp=0;
//             while(count<n){
//                 temp += nums[j]*count;
//                 j = (j+1)%n;
//                 count++;
//             }
//             res = max(res,temp);
//         }
//         return res;
//     }
// };


// Then I took help online from CodeStoryWithMik where helped me realise as how if look at the patter and involve the maths equation it will be solve O(n) time

//Approach (Compute relation and find F(K+1) from F(K) and so on
//T.C : O(n)
//S.C : O(1)
class Solution {
public:
    int maxRotateFunction(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        int F = 0;

        for(int i = 0; i < n; i++) {
            sum += nums[i];
            F += i*nums[i];
        }

        int result = F;

        for(int k = 0; k <= n-1; k++) {
            int newF = F + sum - n*nums[n-1-k];

            result = max(result, newF);

            F = newF;
        }

        return result;
    }
};
