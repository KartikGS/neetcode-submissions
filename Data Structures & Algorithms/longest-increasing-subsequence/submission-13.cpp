class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> tab(nums.size(), 1);
        int res = 1;

        for(int i = 1; i<nums.size(); i++){
            int lis = 1;
            for(int j = 0; j<i; j++){
                if(nums[i]>nums[j]) lis = max(lis, 1+tab[j]);
            }
            tab[i] = lis;
            res = max(res, lis);
        }

        return res;
    }
};
// [1,3,6,7,9,4,10,5,6]
// 1 - 1
// 3 - 2
// 6 - 3
// 7 - 4
// 9 - 5
// 4 - 3