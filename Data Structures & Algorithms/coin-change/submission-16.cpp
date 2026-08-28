class Solution {
public:
	unordered_map<int, int> memo;

    int coinChange(vector<int>& coins, int amount) {
        int res = dfs(coins, amount);
		return res==INT_MAX?-1:res;
    }

	int dfs(vector<int>& coins, int amount){
		if(amount==0) return 0;
		if(amount<0) return INT_MAX;
		if(memo.count(amount)) return memo[amount];

		int res = INT_MAX;
		for(int coin: coins){
			int tmp = dfs(coins, amount-coin);
			if(tmp!=INT_MAX) res = min(res, 1+tmp);
		}
		memo[amount] = res;
		return res;
	}
};
