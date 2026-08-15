class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size(); //10
        int l = 0, res = 0;
        
        while(l<n-2){
            int r = l+1, tmp = 0, maxHeight=-1, maxIdx = -1;
            while(r<n && height[r]<height[l]){
                tmp += height[l]-height[r];
                if(maxHeight<height[r]){
                    maxIdx = r;
                    maxHeight = height[r];
                }
                r++;
            }
            if(r==l+1){
                l++;
            } else if(r==n){
                if(maxIdx!=-1){
                    for(int i = n-1; i>=maxIdx; i--){
                        tmp-=height[l]-height[i];
                    }
                    res+=tmp-((maxIdx-l-1)*(height[l]-maxHeight));
                    l=maxIdx;
                }else{
                    l++;
                }
            } else {
                res+=tmp;
                l=r;
            }
        }

        return res;
    }
};

//0,2,0,3,1,0,1,3,2,1
        //0 sw = false
        //remove 0 as sw = false, keep 2
        //2, 0, sw = true, amt = 2-0
        //3>=2(greatest), final_amt +=amt, amt =0, only 3
        //3, 1 amt += 3-1 = 2
        //3, 0, amt += 3-0 = 5
        //
        
        //new element is greater than or equals to the past greatest element add to final amount

        //3

        //3, 1, 0, 2

        //3, 3- 7-3
        //7-3-1 = 3 * (3-1)

        //if water is not being stored keep both the pointer in the same bar.
        //r++ if less and calculate the temp amount
        //if r greater or equat put temp in final and move both the pointer

        //delete all the extra water