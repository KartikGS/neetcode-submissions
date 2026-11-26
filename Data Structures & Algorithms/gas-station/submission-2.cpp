class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int n = gas.size();
        vector<int> extra_gas(n);

        for(int i = 0; i<n; i++){
            extra_gas[i] = gas[i]-cost[i];
        }
        
        bool rotated = false;
        int i = 0, sum = 0, start = 0;
        while(true){
            sum+=extra_gas[i];
            if(i==n-1){
                i=0;
                rotated = true;
            }else{
                i++;
            }
            if(sum<0){
                if(rotated) return -1;
                sum = 0;
                start = i;
            } else {
                if(start == i) return start;
            }
        }
        return -1;
    }
};

//gas = [1,2,3], cost = [2,3,2]
//extra_gas = [-1, -1, 1]
//going from left to right ,start from 0 if negative restart from next index
//i = 0 No
//i = 1 yes add gas record start
//i = 2 no becomes negative, no ans
//i = 3 yes
//i=0 yes set rotated true
//1=1 yes
//i = 2 yse
//og start reached hence ans
//if not reached and already rotated return -1
