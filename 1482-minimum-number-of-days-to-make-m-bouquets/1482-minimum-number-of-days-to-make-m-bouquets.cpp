class Solution {
public:
    bool f(vector<int>& bloomDay, int m, int k,int n,int day){
      int count = 0;
      int bouquets=0;
      for(int i = 0; i < n; i++) {
         if(bloomDay[i] <= day) {
            count++;

           if(count == k) {
            bouquets++;
            count = 0;
           }
         }
           else {
             count = 0;
           }
       }
       return bouquets>=m;
    }
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n=bloomDay.size();
        int low=1,mid;
        int high=*max_element(bloomDay.begin(),bloomDay.end());
        long a=1L*m*k;
        if(a>n) return -1;
        while(low<=high){
            mid=low+((high-low)/2);
            if(f(bloomDay,m,k,n,mid)) high=mid-1;
            else low=mid+1;
        }
        return low;
    }
};