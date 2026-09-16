class Solution {
public:
    	int trap(vector<int>& height) {
int n = height.size();
vector<int> left(n), right(n);
left[0] = height[0], right[n-1] = height[n-1];
for(int i = 1; i<n; i++){
	left[i] = max(left[i-1], height[i]);
	right[n-1-i] = max(right[n-i], height[n-1-i]);
}
int res = 0;
for(int i = 1; i<n-1; i++){
	res+=min(left[i], right[i])-height[i];
}
return res;
    	}
};

// 0 2 2 3 3 3 3 3 3 3 left
// 3 3 3 3 3 3 3 3 2 1 right
//res 2
