class Solution {
public:
    bool f(vector<int>& nums,int n, int k ,int mid){
        int sum=0;
        int cnt=1;
        for(int i=0;i<n;i++){
           sum+=nums[i];
           if(sum>mid){
            cnt++;
            sum=nums[i];
           }
        }
        if(cnt<=k) return true;
        return false;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+((high-low)/2);
            if(!f(nums,n,k,mid)) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};