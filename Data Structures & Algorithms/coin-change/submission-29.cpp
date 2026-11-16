class Solution {
public:
	int coinChange(vector<int>& coins, int amount) {
	if(amount == 0) return 0;

unordered_set<int> seen;
	seen.insert(amount);

queue<int> q;
q.push(amount);

int res = 0;

while(!q.empty()){
	res++;
	int len = q.size();
	for(int i = 0; i<len; i++){
	int cur = q.front();
	q.pop();
	for(int coin: coins){
		if(cur-coin == 0) return res;
	if(cur-coin>0 && seen.find(cur-coin) == seen.end()){
	q.push(cur-coin);
	seen.insert(cur-coin);
}
}
}
}

return -1;
}
};
