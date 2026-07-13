class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        vector<int> psee(n), nse(n);
        vector<int> pgee(n), nge(n);

        stack<int> st;

        // ----------- Minimum ------------

        // Previous Smaller or Equal
        for(int i = 0; i < n; i++){

            while(!st.empty() && nums[st.top()] > nums[i])
                st.pop();

            psee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Smaller
        for(int i = n-1; i >= 0; i--){

            while(!st.empty() && nums[st.top()] >= nums[i])
                st.pop();

            nse[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // ----------- Maximum ------------

        // Previous Greater or Equal
        for(int i = 0; i < n; i++){

            while(!st.empty() && nums[st.top()] < nums[i])
                st.pop();

            pgee[i] = st.empty() ? -1 : st.top();

            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Greater
        for(int i = n-1; i >= 0; i--){

            while(!st.empty() && nums[st.top()] <= nums[i])
                st.pop();

            nge[i] = st.empty() ? n : st.top();

            st.push(i);
        }

        long long minSum = 0;
        long long maxSum = 0;

        for(int i=0;i<n;i++){

            long long left = i-psee[i];
            long long right = nse[i]-i;

            minSum += 1LL*nums[i]*left*right;

            left = i-pgee[i];
            right = nge[i]-i;

            maxSum += 1LL*nums[i]*left*right;
        }

        return maxSum-minSum;
    }
};