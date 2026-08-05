class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        int maxSum = nums[n-1], curSum = 0;
        for(int i = 0; i<n; i++){
            if(curSum<0) curSum=0;
            curSum+=nums[i];
            maxSum = max(maxSum, curSum);
        }
        return maxSum;
    }
};
