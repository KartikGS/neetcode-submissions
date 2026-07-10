class Solution {
public:
    int rob(vector<int>& nums) {
        if(nums.size() == 0) return 0;
        if(nums.size() == 1) return nums[0];
        if(nums.size() == 2) return max(nums[0], nums[1]);

        vector<int> tab(nums.size(), -1);

        tab[0] = nums[0];
        tab[1] = max(nums[0], nums[1]);
        
        for(int i = 2; i<nums.size(); i++){
            tab[i] = max(nums[i]+tab[i-2], tab[i-1]);
        }

        return tab[nums.size()-1];
    }
};
