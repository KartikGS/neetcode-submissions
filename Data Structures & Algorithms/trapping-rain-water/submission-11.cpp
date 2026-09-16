class Solution {
public:
    	int trap(vector<int>& height) {

int n = height.size();
int res=0;

stack<int> stk;
stk.push(0);

for(int i = 1; i<n; i++){
	while(!stk.empty() && height[stk.top()]<=height[i]){
		int m = stk.top();
		stk.pop();
		if(!stk.empty()){
	int l = height[stk.top()];
	int r = height[i];
	int w = i-stk.top()-1;
	int h = min(l,r)-height[m];
	res += w*h;
}
}
stk.push(i);
}

return res;
    	}
};

// 1,3,2,1
//stk 3, 1
//res 3
