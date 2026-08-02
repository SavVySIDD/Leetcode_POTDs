class Solution {
    typedef pair<int,int> P;
public:
    int minimumPushes(string word) {
        vector<int>hash(26,0);
        for(char c:word){
            hash[c-'a']++;
        }
        priority_queue<int,vector<int>>pq; //max-heap
        for(auto&it:hash){
            if(it!=0)
            pq.push(it);
        }
        int times = 1;
        int res =0;
        while(!pq.empty()){
            int sz = pq.size();
            if(sz>8){
                for(int i=0;i<8;i++){
                    res+= times * pq.top();
                    pq.pop();
                }
            }else{
                while(sz--){
                    res+=times*pq.top();
                    pq.pop();
                }
            }
            times++;
        }
        return res;
    }
};