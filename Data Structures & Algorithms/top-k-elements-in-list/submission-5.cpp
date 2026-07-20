class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> count;

        for(int num: nums) count[num]++;

        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int,int>>> minHeap;

        for(auto item: count){ 
            minHeap.push({item.second, item.first});
            if(minHeap.size()>k){
                minHeap.pop();
            }
        }

        vector<int> res;
        for(int i = k; i>0; i--){
            res.push_back(minHeap.top().second);
            minHeap.pop();
        }
        return res;
    }
};
