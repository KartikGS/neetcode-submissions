class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {

        int n = nums.size();
        vector<int> res(n), prefix(n+1,1), postfix(n+1,1);
        for(int i=1; i<=n; i++){
            prefix[i] = prefix[i-1]*nums[i-1];
        }
        for(int i=n-1; i>=0; i--){
            postfix[i] = postfix[i+1]*nums[i];
        }
        //1, -1, 0, 0, 0, 0
        //0, 0, 6, 6, 3, 1
        //48, 48, 24, 6, 1 
        for(int i = 0; i<n; i++){
            res[i] = prefix[i]*postfix[i+1];
        }
        return res;
    }
};
