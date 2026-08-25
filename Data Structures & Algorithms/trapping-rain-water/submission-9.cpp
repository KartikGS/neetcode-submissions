class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk;
        int res=0;
        for(int i = 0; i<height.size(); i++){
            while(!stk.empty() && height[i]>=height[stk.top()]){
                int m = stk.top();
                stk.pop();
                if(!stk.empty()){
                    int l = stk.top();
                    int r = i;
                    int h = min(height[r],height[l])-height[m];
                    int w = r-l-1;
                    res+=h*w;
                }
            }
            stk.push(i);
        }
        return res;
    }
};
//