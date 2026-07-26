class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int sum = *max_element(nums.begin(), nums.end());
        
        if(sum<=0) return sum;

        int temp = 0;
        for(int i = 0; i< nums.size(); i++){
            temp+=nums[i];
            sum = max(sum, temp);
            if(temp<0){
                temp = 0;
            }
        }
        
        return sum;
    }
};
