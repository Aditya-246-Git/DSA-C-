class Solution {
public:
    bool f(vector<int>& bloomDay, int m, int k,int day){
      int count = 0;
      int bouquets=0;
      for(auto i:bloomDay) {
         if(i <= day) {
            count++;
           if(count == k) {
            bouquets++;
            count = 0;
           }
           if(bouquets==m) return true;
         }
           else {
             count = 0;
           }
       }
       return false;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int low=1,mid;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        if(1L*m*k>n) return -1;
        while(low<=high){
            mid=low+((high-low)/2);
            if(f(bloomDay,m,k,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};