class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int leftMax, rightMax;
        leftMax = height[0];
        rightMax = height[n-1];
        int l = 0, r = n-1, res = 0;
        while(l<r){
            if(leftMax<=rightMax){
                l++;
                leftMax = max(leftMax, height[l]);
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
//n = 10
// lm= 2, rm = 2 
//l 2, r-8
//2