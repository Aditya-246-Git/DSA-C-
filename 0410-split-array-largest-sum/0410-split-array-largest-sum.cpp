class Solution {
public:
    bool f(vector<int>& nums, int k, int mid) {
        int cnt = 1;
        int sum = 0;
        for(int x : nums) {
            if(sum + x > mid) {
                cnt++;
                sum = x;
            }
            else {
                sum += x;
            }
        }
        return cnt <= k;
    }
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        int low=*max_element(nums.begin(),nums.end());
        int high=accumulate(nums.begin(),nums.end(),0);
        while(low<=high){
            int mid=low+((high-low)/2);
            if(!f(nums,k,mid)) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};