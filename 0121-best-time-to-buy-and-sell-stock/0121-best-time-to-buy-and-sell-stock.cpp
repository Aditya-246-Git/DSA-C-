class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int i=0,j=0;
       int mini=INT_MIN;
       while(j<prices.size()){
            int x=prices[j]-prices[i];
            while(x<0){
                i++;
                x=prices[j]-prices[i];
            }
            mini=max(mini,x);
            j++;
       } 
       return mini;
    }
};