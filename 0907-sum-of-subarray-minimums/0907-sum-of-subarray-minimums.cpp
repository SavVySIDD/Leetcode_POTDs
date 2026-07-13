class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {

        int n = arr.size();
        const int MOD = 1e9 + 7;

        vector<int> psee(n), nse(n);
        stack<int> st;

        // Previous Smaller or Equal Element
        for(int i = 0; i < n; i++) {
            while(!st.empty() && arr[st.top()] > arr[i])
                st.pop();
            if(st.empty())
                psee[i] = -1;
            else
                psee[i] = st.top();
            st.push(i);
        }

        while(!st.empty()) st.pop();

        // Next Smaller Element
        for(int i = n - 1; i >= 0; i--) {
            while(!st.empty() && arr[st.top()] >= arr[i])
                st.pop();
            if(st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();
            st.push(i);
        }

        long long ans = 0;
        for(int i = 0; i < n; i++) {
            long long left = i - psee[i];
            long long right = nse[i] - i;
            ans = (ans + (1LL * arr[i] * left % MOD) * right) % MOD;
        }

        return ans;
    }
};