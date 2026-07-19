class Solution {
    typedef pair<int,int> P;
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        for(auto&it:nums){
            mp[it]++;
        }
        priority_queue<P, vector<P>>pq;
        for(auto&it:mp){
            pq.push({it.second,it.first});
        }
        vector<int>res;
        while(k--){
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;
    }
};