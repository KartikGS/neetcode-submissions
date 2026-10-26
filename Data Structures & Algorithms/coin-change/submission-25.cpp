class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if(amount == 0) return 0;
	
vector<bool> seen(amount+1, false);
	
int res = 0;
	
queue<int> q;
	
q.push(amount);
	seen[amount] = true;
	
	while(!q.empty()){
		int len = q.size();
	res++;
		for(int i = 0; i<len; i++){
	int cur = q.front();
		q.pop();
		for(int coin: coins){
		if(cur-coin==0) return res;
if(cur-coin >0 && !seen[cur-coin]){
	q.push(cur-coin);
	seen[cur-coin] = true;
}
}
}
}

	return -1;
}
};



