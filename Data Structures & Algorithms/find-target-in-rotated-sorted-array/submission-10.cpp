class Solution {
public:
    int search(vector<int>& nums, int target) {
        //3,5,6,0,1,2
        //l = 0, r = 6
        //m = 2
        //m>target
        //m is in the left sorted portion because m > r
        //target > l=m+1 else <r l=m+1
        //else r = m-1;
        int l = 0;
        int r = nums.size()-1;

        while(l<=r){
            int m = l+(r-l)/2;
            if(nums[m] == target) return m;
            if(nums[m]>nums[r]){
                if(nums[m]<target || target<nums[l]) l = m+1;
                else r = m-1;
            } else {
                if(nums[m]>target || target>nums[r]) r = m-1;
                else l = m+1;
            }
        }

        return -1;
    }
};
