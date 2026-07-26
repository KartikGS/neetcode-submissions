class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> res(n), postfix(n+1,1);
        int prefix = 1;
        for(int i=n-1; i>=0; i--){
            postfix[i] = postfix[i+1]*nums[i];
        }
        for(int i = 0; i<n; i++){
            res[i] = prefix*postfix[i+1];
            prefix*=nums[i];
        }
        return res;
    }
};
