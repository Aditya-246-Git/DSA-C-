class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int low=0,high=n-1;
        int mid=0;
        int a=INT_MAX;
        while(low<=high){
           mid=low+((high-low)/2);
           if(nums[low]<=nums[mid]){
            a=min(a,nums[low]);
            low=mid+1;
           }
           else{
           a=min(a,nums[mid]);
           high=mid-1;
           } 
      }
      return a;
    }
};