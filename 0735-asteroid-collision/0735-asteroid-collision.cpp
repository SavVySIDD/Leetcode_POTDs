class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        int n =asteroids.size();
        stack<int>st;
        for(auto& it:asteroids){
            bool destroyed = false;
            while(!st.empty() && st.top()>=0 && it<0){
                int sum = st.top()+it;
                if(sum<0){ //negative greater
                    st.pop();
                }
                else if(sum>0){ //positive greater
                    destroyed= true;
                    break;
                }
                else{//sum==0 
                    st.pop();
                    destroyed=true;
                    break;
                }
            }
            if(!destroyed) st.push(it);
        }
        int s = st.size();
        vector<int> res(s);
        int i = s-1;
        while(!st.empty()) {
            res[i] = st.top();
            st.pop();
            i--;
        }
        return res;
    }
};