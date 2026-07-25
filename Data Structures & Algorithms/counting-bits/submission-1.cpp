class Solution {
    vector<int> bitsNum;

    int numOfBits(int num){
        if(bitsNum[num]!=-1) return bitsNum[num];
        int bits = 0;
        int mx = 1, po =0;
        while(mx<=num){
            mx*=2;
            po++;
        }
        po--;
        while(num>0 && po>=0){
            if(bitsNum[num]!=-1) return bits+bitsNum[num];
            if(num>=pow(2,po)){
                bits++;
                num-=pow(2, po);
            }
            po--;
        }
        bitsNum[num] = bits;
        return bits;
    }

public:
    vector<int> countBits(int n) {
        bitsNum.resize(n+1, -1);
        vector<int> res;

        for(int i = 0; i<=n; i++){
            res.push_back(numOfBits(i));
        }

        return res;
    }
};
// 0 --> 0 0
// 1 --> 1 1
// 2 --> 10 1
// 3 --> 11 2
// 4 --> 100 1
// 5 --> 101 2
// 6 --> 110 2
// 7 --> 111 3
// 8 --> 1000 1
// 9 --> 1001 2
// 10 --> 1010 2
// 11 --> 1011 3
// 12 --> 1100 2
// 13 --> 1101 3
// 14 --> 1110 3
// 15 --> 1111 4
// 16 --> 10000 1