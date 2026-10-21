class Solution {
public:
    	int trap(vector<int>& height) {
        		int n = height.size();
int res = 0;
stack<int> stk;
for(int i =0; i<n; i++){
	while(!stk.empty() && height[stk.top()]<=height[i]){
	int m = stk.top();
	stk.pop();
	if(!stk.empty()){
		int r = height[i];
		int l = height[stk.top()];
		int h = min(r, l) - height[m];
		int w = i-stk.top()-1;
		res+=h*w;
}
}
stk.push(i);
}
return res;
    	}
};

