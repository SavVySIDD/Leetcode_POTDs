class Solution {
    static bool comparator(vector<int>& a, vector<int>& b) {
                if(a[0] == b[0])
                    return a[1] > b[1];      // descending end
                return a[0] < b[0];          // ascending start
            }
public:
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(),comparator);

        int count = 0;
        int maxRight = INT_MIN;

        for(auto &it : intervals) {

            if(it[1] > maxRight) {
                count++;
                maxRight = it[1];
            }
        }

        return count;
    }
};