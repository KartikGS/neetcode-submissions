class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // -4, -1, -1, 0, 1, 2

        vector<vector<int>> ans;
        set<vector<int>> dupTkr;

        int n = nums.size(); //6
        for(int i = 0; i < n; i++){
            int target = -nums[i]; //1
            int j = 0;
            int k = n-1;
            while(j<k){
                if(j==i){
                    j++;
                    continue;
                }
                if(k==i){
                    k--;
                    continue;
                }
                int sum = nums[j]+nums[k];
                if(sum==target){
                    vector<int> trip = {nums[i], nums[j], nums[k]};
                    sort(trip.begin(), trip.end());
                    if(dupTkr.find(trip)==dupTkr.end()) {
                        ans.push_back(trip);
                        dupTkr.insert(trip);
                    }
                    j++;
                    k--;
                } else if (sum>target) {
                    k--;
                } else {
                    j++;
                }
            }
        }

        return ans;
    }
};
