class Solution {
public:
int characterReplacement(string s, int k) {
	int l = 0, r=0;
	vector<int> cnt(26);
	int res = 1;
	while(r<s.size()){
		cnt[s[r]-'A']++;
		int maxFreq = *max_element(cnt.begin(), cnt.end());
		if(r-l+1-maxFreq<=k){
			res=max(res, r-l+1);
	r++;
} else {
	do{
		cnt[s[l]-'A']--;
		l++;
		maxFreq = *max_element(cnt.begin(), cnt.end());
} while(r-l+1-maxFreq>k);
r++;
    }
}
return res;
}
};
