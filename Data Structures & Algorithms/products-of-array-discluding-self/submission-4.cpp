class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
		int n = nums.size();//4
		vector<int> res(n, 1);// 1 24 12 8

		for(int i = 1; i<n; i++) res[i] = res[i-1]*nums[i-1];

		int postfix = nums[n-1];//48

		for(int i = n-2; i>=0; i--){
			res[i] = res[i]*postfix;
			postfix*=nums[i];
		}

		return res;
    }
};
