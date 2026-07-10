class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        if(amount == 0) return 0;

        vector<int> tab(amount, INT_MAX);

        for(int i = 0; i<amount; i++){
            int res = INT_MAX;
            for(int coin:coins){
                if(i-coin+1 == 0){
                    res = 1;
                    break;
                }
                else if(i-coin+1>0 && tab[i-coin] != INT_MAX){
                    res = min(res, 1+tab[i-coin]);
                }
            }
            tab[i] = res;
        }
        return tab[amount -1]==INT_MAX?-1:tab[amount-1];
    }
};
