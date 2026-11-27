class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        unordered_map<int, vector<pair<int, int>>> adj;
        for(const auto time: times) adj[time[0]-1].emplace_back(time[2], time[1]-1);

        vector<int> minTimes(n, INT_MAX);
        
        priority_queue<pair<int, int>, vector<pair<int,int>>, greater<pair<int, int>>> minHeap;
        minHeap.emplace(0, k-1);

        unordered_set<int> seen;
        
        while(!minHeap.empty()){
            auto [time, node] = minHeap.top();
            minHeap.pop();
            if(seen.count(node)) continue;
            seen.insert(node);
            minTimes[node] = time;
            cout<<time<<"\n";
            for(auto item: adj[node]){
                minHeap.emplace(time+item.first, item.second);
            }
        }
        
        int res = *max_element(minTimes.begin(), minTimes.end());
        return res==INT_MAX?-1:res;
    }
};
