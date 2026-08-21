class Solution {
public:
    int smallestDivisor(vector<int>& nums, int threshold) {
        int low=1,mid;
        int n=nums.size();
        int high=*max_element(nums.begin(),nums.end());
        while(low<=high){
            mid=low+((high-low)/2);
            int s=0;
            for(auto i: nums){
               s+=(i+mid-1)/mid;
            }
            if(s>threshold) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};