class Solution {
public:
    vector<int> countBits(int n) {
        vector<int> res(n+1);

        for(int i = 0; i<=n; i++){
            int num = i;
            int tmp = 0;
            while(num>0){
                tmp++;
                num&=(num-1);
            }
            res[i] = tmp;
        }

        return res;
    }
};
