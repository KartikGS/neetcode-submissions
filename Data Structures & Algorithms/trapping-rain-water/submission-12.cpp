class Solution {
public:
    	int trap(vector<int>& height) {
		int n = height.size();
int l = 0, r = n-1;
int maxl = height[l], maxr = height[r];
int res = 0;
while(l<r){
	if(maxl<=maxr){
		l++;
		maxl = max(height[l], maxl);
	res+= maxl-height[l];
} else {
	r--;
	maxr = max(height[r], maxr);
	res+=maxr-height[r];
}
}
return res;
    	}
};
