class Solution {
public:
    bool f(vector<int>& weights, int days,int cap){
        int sum=0;
        int dday=1;
         for(auto i: weights){
            sum+=i;
           if(sum>cap){
            dday++;
            sum=i;
           }
           if(dday>days) return false;
         }
         return true;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int low=*max_element(weights.begin(),weights.end());
        int mid;
        int high=0;
        for(auto i: weights){
            high+=i;
        }
        while(low<=high){
            mid=low+((high-low)/2);
            if(f(weights,days,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};