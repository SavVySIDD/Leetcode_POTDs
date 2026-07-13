class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n =asteroids.size();
        stack<int>st;
        vector<int>res;
        for(auto& it:asteroids){
            bool destroyed = false;
            while(res.size()!=0 && res.back()>=0 && it<0){
                int sum = res.back()+it;
                if(sum<0){ //negative greater
                    res.pop_back();
                }
                else if(sum>0){ //positive greater
                    destroyed= true;
                    break;
                }
                else{//sum==0 
                    res.pop_back();
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed) res.push_back(it);
        }
        return res;
    }
};