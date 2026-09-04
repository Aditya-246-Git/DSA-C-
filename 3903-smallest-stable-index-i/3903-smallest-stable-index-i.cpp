class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int prevmax=INT_MIN;
        int n=nums.size();
        for(int i=0;i<n;i++){
           prevmax=max(prevmax,nums[i]);
           int nextmin=INT_MAX;
           for(int j=i;j<n;j++){
             if(nextmin>nums[j]){
                nextmin=nums[j];
             }
           }
           if(prevmax-nextmin<=k){
              return i;
              break;
           }
        }
        return -1;

    }
};