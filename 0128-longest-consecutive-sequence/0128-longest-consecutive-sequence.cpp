class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s;
        for(auto it: nums){
            s.insert(it);
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