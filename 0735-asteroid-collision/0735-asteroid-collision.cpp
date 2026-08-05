class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int>res;
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            bool destroyed = false;
            while(!res.empty() && res.back()>0 && asteroids[i]<0){
                int sum = res.back() + asteroids[i];
                if(sum<0){
                    res.pop_back();
                }else if(sum>0){
                    destroyed = true;
                    break;
                }else{
                    res.pop_back();
                    destroyed = true;
                    break;
                }
            }
            if(!destroyed){
                res.push_back(asteroids[i]);
            }
        }
        return res;
    }
};