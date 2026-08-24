class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
       int n=nums1.size();
       int m=nums2.size();
       if(m<n) return findMedianSortedArrays(nums2,nums1);
       int low=0;
       int high=n;
       int total=(n+m+1)/2;
       while(low<=high){
        int cnt1=low+((high-low)/2);
        int cnt2= total-cnt1;
        int l1=cnt1>0?nums1[cnt1-1]:INT_MIN;
        int l2=cnt2>0?nums2[cnt2-1]:INT_MIN;
        int r1=cnt1<n?nums1[cnt1]:INT_MAX;
        int r2=cnt2<m?nums2[cnt2]:INT_MAX;
        if(l1<=r2 && l2<=r1){
            if((n+m)%2==0) return (max(l1,l2)+min(r1,r2))/2.0;
            return max(l1,l2);
        }
        else if(l1>r2){
            high=cnt1-1;

        }
        else low=cnt1+1;
       } 
       return -1;
    }
};