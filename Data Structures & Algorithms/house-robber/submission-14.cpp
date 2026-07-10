class Solution {
public:
    int rob(vector<int>& nums) {
        int rob1=0, rob2=0;//3 is the house to rob, rob2 is the neighbor, rob1 neighbor of rob2

        for(auto i: nums){
            int temp = max(i+rob1, rob2);
            rob1= rob2;
            rob2 = temp;
        }

        return rob2;
    }
};
