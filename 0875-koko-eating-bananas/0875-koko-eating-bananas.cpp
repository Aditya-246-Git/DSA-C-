class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low=1,mid=0;
        int n=piles.size();
        int high = *max_element(piles.begin(), piles.end());
        while(low<=high){
            mid=low+(high-low)/2;
            long long time=0;
            for(auto i: piles){
                time+=(i+mid-1)/mid;
            }
            if(time>h) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};