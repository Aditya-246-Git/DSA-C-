class Solution {
public:
    int smallestNumber(int n, int t) {
        int i =n ;
        while(i>0){
            int a=i;
            int b=1;
            while(a>0){
                b*=a%10;
                a=a/10;
            }
            if(b%t==0) return i;

            i++;
        }
        return 0;
    }
};