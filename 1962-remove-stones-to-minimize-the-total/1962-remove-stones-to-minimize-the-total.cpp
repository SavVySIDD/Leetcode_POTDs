class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int>pq(piles.begin(),piles.end()); //max-heap
        int sum = accumulate(begin(piles),end(piles),0);
        while(k--){
            int take = pq.top();
            pq.pop();
            sum-=take/2;
            take = take%2==0? take/2 : (take+1)/2;
            pq.push(take);
        }
        return sum;
    }
};