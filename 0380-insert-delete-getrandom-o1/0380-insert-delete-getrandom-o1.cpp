class RandomizedSet {
    // I was using set at first but it can't be used as it won't be able to perform the get random in O(1) so we switched to vector and map, as map is only used to track indexes as it would be required for O(1) removal from vector and now using indexing we can get random in O(1)
    vector<int>v;
    unordered_map<int,int>mp;
public:
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(mp.count(val)) return false;
        v.push_back(val);
        mp[val] = v.size()-1;
        return true;
    }
    
    bool remove(int val) {
        if(!mp.count(val)) return false;
        int idx = mp[val];
        int lastEle = v.back();
        v.back() = val; // added the val to the last index
        v[idx] = lastEle; // added the last element to the index of the element to be delted
        mp[lastEle] = idx;// made the changes to the map
        v.pop_back();
        mp.erase(val);
        return true;
    }
    
    int getRandom() {
        int n = v.size();
        int randIdx = rand()%n; //0..n-1
        return v[randIdx];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */