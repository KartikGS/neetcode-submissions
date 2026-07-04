class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = INT_MIN;
        for(int i = 0; i<nums.size(); i++){
            int temp = 0;
            for(int j = i;j<nums.size(); j++){
                temp = temp+nums[j];
                sum = max(sum, temp);
            }
        }
        return sum;
    }
};
