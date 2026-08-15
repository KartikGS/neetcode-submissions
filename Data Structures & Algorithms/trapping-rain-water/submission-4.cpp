class Solution {
public:
    int trap(vector<int>& height) {
        int l =0, r = height.size()-1, res =0, leftMax = height[l], rightMax = height[r];
        while(l<r){
            if(leftMax<=rightMax){
                l++;
                leftMax= max(leftMax, height[l]);
                res+=leftMax-height[l];
            } else {
                r--;
                rightMax = max(rightMax, height[r]);
                res+=rightMax-height[r];
            }
        }
        return res;
    }
};
