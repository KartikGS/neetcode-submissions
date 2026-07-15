class Solution {
public:
    	int lengthOfLIS(vector<int>& nums) {
        		vector<int> dp;
		
		dp.push_back(nums[0]);
		int lis = 1;
		for(int i = 1; i<nums.size(); i++){
            cout<<nums[i]<<" "<<dp.back()<<"\n";
			if(dp.back()<nums[i]){
				lis++;
				dp.push_back(nums[i]);
				continue;
}
int idx = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
dp[idx] = nums[i];
}
		return lis;
    	}
};

//[9,1,4,2,3,3,7]
// 1, 2,3, 7
//[0,3,2,3,1,3]
// 0, 1, 3, - 
