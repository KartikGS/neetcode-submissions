class Solution {
public:
    	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        		//Input: nums = [1,2,1,0,4,2,6], k = 3
		// n=7
		// 2 2 4 1 1 
		// dq: 4

		int n = nums.size();
		vector<int> res(n-k+1);
		
deque<int> dq;

		for(int i = 0; i<n; i++){
	if(i>=k && nums[i-k] == dq.front()) dq.pop_front();
	while(!dq.empty() && dq.back()<nums[i]) dq.pop_back();
	dq.push_back(nums[i]);
	if(i>=k-1) res[i-k+1] = dq.front();
}

return res;
    	}
};


