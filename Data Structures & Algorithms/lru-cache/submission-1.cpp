class LRUCache {
public:
    //cache
    unordered_map<int, int> mp;
    int capacity;
    
    //LRU logic
    int counter;
    unordered_map<int, int> coc; //cache to counter
    
    LRUCache(int capacity) {
         this->capacity = capacity;
         counter = 0;
    }
    
    int get(int key) {
        if(mp.count(key)){
            //increment the usage
            coc[key] = counter;
            counter++;
            return mp[key];
        }
        return -1;
    }
    
    void put(int key, int value) {
        if(mp.size()==capacity && !mp.count(key)){
            //remove the LRU
            int minC=INT_MAX;
            int minK;
            for(auto it: coc){
                if(it.second<minC){
                    minC = it.second;
                    minK = it.first;
                }
            }
            coc.erase(minK);
            mp.erase(minK);
        }
        mp[key] = value;
        coc[key] = counter;
        counter++;
        return;
    }
};
