class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int> minval(n);
        minval[n-1]=nums[n-1];
        for(int j=n-2;j>=0;j--){
           minval[j]=min(minval[j+1],nums[j]);
        }
        int prevmax=INT_MIN;
        for(int i=0;i<n;i++){
           prevmax=max(prevmax,nums[i]);
           if(prevmax-minval[i]<=k){
              return i;
           }
        }
        return -1;
    }
};