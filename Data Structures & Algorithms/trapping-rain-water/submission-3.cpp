class Solution {
public:
    int trap(vector<int>& height) {
        int res = 0, n = height.size();
        stack<int> stk;

        for(int i = 0; i<n; i++){
            while(!stk.empty() && height[i] >= height[stk.top()]){
                int m = stk.top();
                stk.pop();
                if(!stk.empty()){
                    int r = height[i];
                    int l = height[stk.top()];
                    int w = i-stk.top()-1;
                    int h = min(r,l)-height[m];
                    res+=w*h;
                }
            }
            stk.push(i);
        }

        return res;
    }
};
