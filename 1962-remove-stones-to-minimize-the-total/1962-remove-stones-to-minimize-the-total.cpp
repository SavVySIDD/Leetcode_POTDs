class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(),piles.end()); //max-heap
        // for(auto&it:piles) pq.push(it);
        while(k--){
            int take = pq.top();
            pq.pop();
            take = take%2==0? take/2 : (take+1)/2;
            pq.push(take);
        }
        int sum =0;
        while(!pq.empty()){
            sum+=pq.top();
            pq.pop();
        }
        return sum;
    }
};