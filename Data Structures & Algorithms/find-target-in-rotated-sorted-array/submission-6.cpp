class Solution {
public:
    int search(vector<int>& nums, int target) {
        int i = 0;
        int j = nums.size()-1;

        int k = -1;
        while(nums[i]>nums[j]){//4, 4
            k = (i+j)/2;//3
            if(nums[k]>=nums[i]){
                i=k+1;//4
            } else {
                j = k;
            }
        }
        // cout<<i;

        if(k==-1){
            i = 0;
            j = nums.size()-1;
        } else if(target>=nums[0]){
            cout<<1;
            j = i-1;
            i=0;
        } else{
            cout<<2;
            j = nums.size()-1;
        }
        // cout<<target<<nums[0];

        while(i<=j){//4,5
            k = (i+j)/2;//4
            if(nums[k]==target) return k;
            else if(nums[k]>target) j = k-1;
            else i = k+1;
        }

        return -1;
    }
};
