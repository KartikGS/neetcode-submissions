class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int l = 1;
        int r = * max_element(piles.begin(), piles.end());
        int res = r;
        while(l<=r){
            int k = l+(r-l)/2;
            long long hours = 0;
            for(int pile:piles){
                hours+=ceil(static_cast<double>(pile)/k);
            }
            if(hours<=h){
                res = k;
                r = k-1;
            } else {
                l = k+1;
            }
        }
        return res;
    }
};
