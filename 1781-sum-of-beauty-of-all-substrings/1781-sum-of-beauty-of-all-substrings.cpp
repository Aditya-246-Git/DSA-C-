class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int sum=0;
        for(int i=0;i<n;i++){
            int freq[26]={0};
            for(int j=i;j<n;j++){
                freq[s[j]-'a']++;
                int mini=INT_MAX;
                int maxi=INT_MIN;
                for(auto a:freq){
                  if(a>0){
                     mini=min(mini,a);
                     maxi=max(maxi,a);
                  }
                }
                sum+=maxi-mini;
            }
        }
        return sum;
    }
};