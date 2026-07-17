class Solution {
public:
    int rob(vector<int>& nums) {
        int one = 0;
        int two = 0;
        
        for( int i = 0; i<nums.size(); i++){
            int temp = max(one, nums[i]+two);
            two = one;
            one = temp;
        }

        return one;
    }
};
