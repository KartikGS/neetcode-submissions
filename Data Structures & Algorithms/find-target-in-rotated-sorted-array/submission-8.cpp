class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size()-1;

        while(l<r){
            int m = (l+r)/2;
            if(nums[m]>nums[r]){
                l = m+1;
            } else{
                r = m;
            }
        }

        int p = l;
        l = 0;
        r = nums.size()-1;
        if(nums[p]<=target && nums[r]>=target) return binary_search(nums, target, p, r);
        return binary_search(nums, target, l, p-1);
    }

    int binary_search(vector<int>& nums, int target, int l, int r){
        while(l<=r){
            int m = (l+r)/2;

            if(nums[m]==target) return m;
            else if(nums[m]>target) r = m-1;
            else l = m+1;
        }

        return -1;
    }
};
