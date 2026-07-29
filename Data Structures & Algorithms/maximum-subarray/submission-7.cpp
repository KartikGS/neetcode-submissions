class Solution {
public:
    int maxSubArray(vector<int>& nums) {
		int maxSum = nums[0], tmp = 0;

		for(int num:nums){
			if(tmp<0) tmp = 0;
			tmp+=num;
			maxSum = max(maxSum, tmp);
		}

		return maxSum;
    }
};
