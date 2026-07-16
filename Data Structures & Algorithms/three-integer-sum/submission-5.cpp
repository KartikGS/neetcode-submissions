class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        // -1,0,1,2,-1,-4
        // -1, -1, 0, 1, 2, 4
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;

        for(int i = 0; i<nums.size()-2;i++){
            if(nums[i]>0) break;
            if(i>0 && nums[i]==nums[i-1]) continue;

            int l = i+1;
            int r = nums.size()-1;

            while(l<r){
                long sum = nums[i]+nums[l]+nums[r];
                if(sum==0){
                    res.push_back({nums[i], nums[l], nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l] == nums[l-1]) l++;
                } else if (sum > 0){
                    r--;
                } else {
                    l++;
                }
            }
        }
        return res;
    }
};
