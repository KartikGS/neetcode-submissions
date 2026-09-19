class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
		if(amount == 0) return 0;
		queue<int> q;
		unordered_set<int> seen;
		
		int res = 0;
		q.push(0);
		seen.insert(0);

		while(!q.empty()){
	int len = q.size();
	res++;
	for(int i = 0; i<len; i++){
int cur = q.front();
q.pop();
	for(int coin: coins){
		if(coin+cur == amount) return res;
		if(coin+cur<amount && seen.find(coin+cur)==seen.end()){
	q.push(cur+coin);
	seen.insert(cur+coin);
}
}
}
}

		return -1;
    	}
};
