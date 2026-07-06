class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end()); // -4, -1, -1, 0, 1, 2

        vector<vector<int>> ans;

        int n = nums.size(); //6
        for(int i = 0; i < n-2; i++){
            if(i>0 && nums[i]==nums[i-1]) continue;
            int target = -nums[i]; //1
            int j = i+1;
            int k = n-1;
            while(j<k){
                int sum = nums[j]+nums[k];
                if(sum==target){
                    vector<int> trip = {nums[i], nums[j], nums[k]};
                    ans.push_back(trip);
                    while(j<n-1 && nums[j]==nums[j+1]) j++;
                    while(k>1 && nums[k]==nums[k-1]) k--;
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
