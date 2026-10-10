#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>

class Solution {
public:
    long long minSumSquareDiff(vector<int>& nums1,
                               vector<int>& nums2,
                               int k1, int k2) {
        int n = nums1.size();
        long long total_diff = 0;
        int max_val = 0;
        
        // Find absolute differences and the maximum difference
        vector<int> diff(n);
        for(int i = 0; i < n; i++) {
            diff[i] = abs(nums1[i] - nums2[i]);
            total_diff += diff[i];
            max_val = max(max_val, diff[i]);
        }
        
        long long k = (long long)k1 + k2;
        
        // If total operations can cover all differences entirely, return 0
        if(total_diff <= k) {
            return 0;
        }
        
        // Frequency array to count occurrences of each difference value
        vector<long long> count(max_val + 1, 0);
        for(int d : diff) {
            count[d]++;
        }
        
        // Greedily reduce from the largest difference downwards in O(max_val) time
        for(int i = max_val; i > 0; --i) {
            if(count[i] > 0) {
                long long reduce_ops = min(k, count[i]);
                k -= reduce_ops;
                count[i] -= reduce_ops;
                count[i - 1] += reduce_ops;
                
                if(k == 0) {
                    break;
                }
            }
        }
        
        // Calculate the final sum of squared differences
        long long ans = 0;
        for(int i = 0; i <= max_val; ++i) {
            if(count[i] > 0) {
                ans += (1LL * i * i) * count[i];
            }
        }
        
        return ans;
    }
};