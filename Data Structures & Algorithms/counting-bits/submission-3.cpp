class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);
        for(int i=0; i<=n; i++){
            int num = i;
            while(num){
                res[i]++;
                num&=num-1;
            }
        }
        return res;
    }
};
