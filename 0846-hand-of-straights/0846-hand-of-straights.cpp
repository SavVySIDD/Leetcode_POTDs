class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        int n = hand.size();
        if(n%groupSize!=0) return false;
        map<int,int>mp;
        for(auto&it:hand){
            mp[it]++;
        }
        while(!mp.empty()){
            // Now mp.begin() returns the iterator that points to the pair that is why we have to use ->
            int curr = mp.begin()->first;
            for(int i=0;i<groupSize;i++){
                if(!mp.count(curr+i)) return false;
                mp[curr+i]--;
                if(mp[curr+i]<1) mp.erase(curr+i);
            }
        }
        return true;
    }
};