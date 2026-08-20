class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return nums[0];
        int one = nums[0];
        int two = max(nums[0], nums[1]);
        for(int i = 2; i<n; i++) {
            int temp = two;
            two = max(two, nums[i]+one);
            one = temp;
        }
        return two;
    }
};
