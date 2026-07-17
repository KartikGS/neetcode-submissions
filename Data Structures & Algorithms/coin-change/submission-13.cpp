class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if (amount == 0) return 0;

        queue<int> q;
        q.push(0);
        vector<bool> seen(amount+1, false);
        seen[0] = true;
        int res = 0;

        while(!q.empty()){
            res++;
            int len = q.size();
            for(int i = 0; i<len; i++){
                int cur = q.front();
                q.pop();
                for(int coin: coins){
                    int nxt = cur+coin;
                    if(nxt == amount) return res;
                    if(nxt>amount || seen[nxt]) continue;
                    q.push(nxt);
                    seen[nxt] = true;
                }
            }
        }

        return -1;   
    }
};
