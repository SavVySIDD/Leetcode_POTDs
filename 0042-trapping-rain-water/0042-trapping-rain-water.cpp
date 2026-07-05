class Solution {
public:
    int trap(vector<int>& height) {
        if (height.empty()) return 0; 
        
        int n = height.size();
        int res = 0;
        vector<int> prefixMax(n);
        vector<int> suffixMax(n);
        
        prefixMax[0] = height[0]; // 0,1,1,2,2,2,2,3,3,3,3,3
        for (int i = 1; i < n; i++) {
            prefixMax[i] = max(height[i], prefixMax[i - 1]);
        }
        
        suffixMax[n - 1] = height[n - 1]; // 3,3,3,3,3,3,3,3,2,2,2,1
        for (int i = n - 2; i >= 0; i--) {
            suffixMax[i] = max(height[i], suffixMax[i + 1]);
        }
        
        for (int i = 0; i < n; i++) {
            res += min(prefixMax[i], suffixMax[i]) - height[i];
        }
        
        return res;
    }
};