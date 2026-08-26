class Solution {
public:
    int maxDepth(string s) {
      int cnt=0;
      int n=s.size();
      int maxi=INT_MIN;
      for(auto a:s){
        if(a=='(') cnt++;
        else if(a==')') cnt--;

        maxi=max(cnt,maxi);
      }
      return maxi;
    }
};