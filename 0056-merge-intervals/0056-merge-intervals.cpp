class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int n=intervals.size();
        sort(intervals.begin(),intervals.end());
        vector<vector<int>> ans;
        ans.push_back(intervals[0]);
        for(int i=1;i<n;i++){
           int s=ans.back()[1];
           int e=intervals[i][0];
           if(s>=e){
            s=max(intervals[i][1],s);
            ans.back()[1]=s;
           } 
           else{
             ans.push_back(intervals[i]);
           }
        }
        return ans;
    }
};