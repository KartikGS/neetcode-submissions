class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int res = 0;
        stack<int> s;
        for(int i = 0; i<n; i++){
            while(!s.empty() && height[i]>=height[s.top()]){
                int m = s.top();
                s.pop();
                if(!s.empty()){
                    int w = i-s.top()-1;
                    int h = min(height[i], height[s.top()]);
                    h = max(height[m], h)-height[m];
                    res+=w*h;
                }
            }
            s.push(i);
        }
        return res;
    }
};
//n = 10
//res = 0
//3 4  
//m = 5