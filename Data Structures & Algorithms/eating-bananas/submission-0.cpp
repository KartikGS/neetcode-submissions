class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
	//h>= ceil[(a1/k)+a2/k …] = time
	//min k- time  should be as close h

//what if h is 0; -1 (same for all other impossible cases)
//start k =1; 
  //      for each pile sum+=ciel(ai/k);
//	<h
//	ans = k
//O(K*N)
//min hours we need  = N
//1 - N / n/2
//O(N*log(K)) 
	int mp = *max_element(piles.begin(), piles.end());
	int l = 1;
	int r = mp;
	int ans = -1;
	while(l<=r){
	    int m = l + (r-l)/2;
	    int sum = 0;
	    for(auto i: piles){
	    	sum+=(i/m)+(i%m==0?0:1);
            cout<<i<<" "<<ceil(i/m)<<" ";
        }
        cout<<"\n"<<sum<<" "<<m<<'\n';
        if(sum>h){
	        l  =  m+1;
        } else {
	        ans = m;
	        r = m-1;
        }
    }
	return ans;
    }
};


