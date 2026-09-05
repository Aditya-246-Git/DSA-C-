class Solution {
public:
    int mod=1e9+7;
    int nthMagicalNumber(int n, int a, int b) {
        long long low=1LL;
        long long high=1LL*n*min(a,b);
        long long lcm = 1LL*a/gcd(a,b)*b;
        while(low<=high){
            long long mid=low+((high-low)/2);
            int count = mid/a+mid/b-mid/lcm;
            if(count<n){
              low=mid+1;
            }
            else {
                high=mid-1;
            }
        }
        return low % mod;
    }
};