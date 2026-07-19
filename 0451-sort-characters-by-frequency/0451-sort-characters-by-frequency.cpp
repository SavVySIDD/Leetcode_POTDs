class Solution {
    typedef pair<char,int>P;
    struct lambda{
        bool operator()(P&a, P&b){
            return a.second < b.second; //max-heap
        }
    };
public:
    string frequencySort(string s) {
        priority_queue<P,vector<P>,lambda>pq;
        unordered_map<char,int>mp;
        for(auto&it:s){
            mp[it]++;
        }
        for(auto&it:mp){
            pq.push({it.first,it.second});
        }
        string res;
        while(!pq.empty()){
            auto temp = pq.top();
            pq.pop();
            res.append(temp.second,temp.first);
        }
        return res;
    }
};