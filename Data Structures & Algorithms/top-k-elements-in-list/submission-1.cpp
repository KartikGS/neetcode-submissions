class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<vector<int>> freq(nums.size()+1, vector<int>(0));
        unordered_map<int, int> mp;

        for(int num: nums){ 
            mp[num]++;
        }

        for(auto i:mp){
            freq[i.second].push_back(i.first);
        }

        vector<int> res;
        int n = nums.size();
        for(int i = 0;i<k;i++){
            
            while(n>=0 && freq[n].empty()) n--;
            
            if(n==-1) break; 
            
            res.push_back(freq[n].back());
            freq[n].pop_back();
        }
        return res;
    }
};
