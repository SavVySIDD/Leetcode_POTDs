class LRUCache {
    list<int>lru; //key
    map<int, pair<list<int>::iterator, int>> cache; //key,{Address,value}
    int n;
public:
    LRUCache(int capacity) {
        n = capacity;
    }
    
    void makeRecent(int key){
        lru.erase(cache[key].first);
        lru.push_front(key);
        cache[key].first = lru.begin();
    }

    int get(int key) {
        if(!cache.count(key)){
            return -1;
        }
        makeRecent(key);
        auto it = cache[key];
        return it.second; //val
    }
    
    void put(int key, int value) {
        if(cache.count(key)){//already present
            cache[key].second = value;
            makeRecent(key);
        }else{
            lru.push_front(key);
            cache[key] = {lru.begin(),value};
            n--;
        }

        if(n<0){
            n++;
            cache.erase(lru.back());
            lru.pop_back();
        }
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */