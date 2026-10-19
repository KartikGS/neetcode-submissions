class Solution {
public:
	vector<int> memo;

int lengthOfLIS(vector<int>& nums) {
		int n = nums.size();
memo.resize(n, -1);
int res = 1;
for(int i = 0; i<n; i++){
	res = max(res, dfs(i, nums));
}
return res;
}

int dfs(int i, const vector<int>& nums){
	if(memo[i]!=-1) return memo[i];
	int res = 1;
for(int j = i+1; j<nums.size(); j++){
if(nums[j]>nums[i]) res = max(res, 1+dfs(j, nums));	
}
memo[i] = res;
	return res;
}
};



