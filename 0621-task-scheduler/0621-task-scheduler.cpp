class Solution {
public:
    int leastInterval(vector<char>& tasks, int p) {
        int n = tasks.size();
        unordered_map<char, int> mp;
        
        for(char &ch : tasks) {
            mp[ch]++;
        }
        priority_queue<int> pq; //max 
        int time = 0;
        for(auto &it : mp) {
            pq.push(it.second);
        }
        while(!pq.empty()) {
            vector<int> temp;
            for(int i = 1; i<=p+1; i++) { //p+1 because we have to wait for p times after performing the same task.
                if(!pq.empty()) {
                    int freq = pq.top();
                    freq--;
                    temp.push_back(freq); 
                    pq.pop();
                }
            }
            for(int &freq : temp) {
                if(freq > 0)
                    pq.push(freq);
            }
            if(pq.empty()) //all processes finished
                time += temp.size();
            else
                time += (p+1); //we finished p+1 tasks above in the loop
        }
        
        return time;
    }
};