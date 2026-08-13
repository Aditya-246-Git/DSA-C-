class Solution {
public:
    int maxArea(vector<int>& nums) {
        int i=0;
        int j=nums.size()-1;
        int area=0;
        while(i<j){
    
            int x=min(nums[i],nums[j]);
            area=max(area,x*(j-i));
            if(nums[i]<nums[j]) i++;
            else j--;
        }
        return area;
    }
};