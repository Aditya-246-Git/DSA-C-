class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        if(nums.size()==0) return 0;
        for(int it=0;it<nums.size();it++){
            s.insert(nums[it]);
        }
        int maxcnt=0;
        for(auto i: s){
            if(s.find(i-1)==s.end()){
                int cnt=1;
                int x=i;
                while(s.find(x+1)!=s.end()){
                    cnt++;
                    x++;
                }
                maxcnt=max(cnt,maxcnt);
            }
        }
        return maxcnt;
    }
};