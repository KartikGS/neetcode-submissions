class Solution {
public:
    	int trap(vector<int>& height) {
        		int n = height.size();
vector<int> leftMax(n), rightMax(n);
leftMax[0] = height[0], rightMax[n-1] = height[n-1];
for(int i = 1; i<n; i++){
	leftMax[i] = max(leftMax[i-1], height[i]);
	rightMax[n-1-i] = max(rightMax[n-i], height[n-1-i]);
}
int res = 0;
for(int i =1; i<n-1; i++){
	res+=min(leftMax[i], rightMax[i]) - height[i];
}
return res;
    	}
};

