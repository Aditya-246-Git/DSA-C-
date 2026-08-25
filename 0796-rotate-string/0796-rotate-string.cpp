class Solution {
public:
    bool rotateString(string s, string goal) {
        string result=s+s;
        if(s.size()!=goal.size()) return false;
        if(result.find(goal)!=string::npos) return true;
        return false;
    }
};