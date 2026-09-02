bool comp(pair<int,char> a, pair<int,char> b){
            return a.first > b.first;
        }
class Solution {
public:
    string frequencySort(string s) {
        int freq[128] = {0};
        for(char ch : s) {
            freq[ch]++;
        }
        vector<pair<int,char>> v;
        for(int i = 0; i < 128; i++) {
            if(freq[i] > 0) {
                v.push_back({freq[i], (char)i});
            }
        }
        sort(v.begin(), v.end(), comp);
        string ans = "";
        for(auto &p : v) {
            ans += string(p.first, p.second);
        }
        return ans;
    }
};