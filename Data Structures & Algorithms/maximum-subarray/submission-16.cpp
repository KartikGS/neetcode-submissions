class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int n = nums.size();
		int maxSum = nums[0], curSum = nums[0];
		for(int i = 1; i<n; i++){
			if(curSum<0){
				curSum = 0;
			}
			curSum+=nums[i];
			maxSum = max(maxSum, curSum);
		}
		return maxSum;
    }
};
