class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
         int low=1,high=0,mid=0;
         int n=piles.size();
        for(int i=0;i<n;i++){
           high=max(high,piles[i]);
        }
        
        while(low<=high){
            mid=low+(high-low)/2;
            long long time=0;
            for(int i=0;i<n;i++){
                time+=ceil((piles[i]+mid-1)/mid);
            }
            if(time>h) low=mid+1;
            else high=mid-1;
        }
        return low;
    }
};