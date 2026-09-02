class Solution {
public:
    string reverseWords(string s) {
        
        stringstream ss(s);
        string word;
        vector<string> words;

        // words separate cheyyadam
        while(ss >> word) {
            words.push_back(word);
        }

        // words reverse cheyyadam
        reverse(words.begin(), words.end());

        // answer build cheyyadam
        string ans = "";

        for(int i = 0; i < words.size(); i++) {
            if(i > 0) {
                ans += " ";
            }

            ans += words[i];
        }

        return ans;
    }
};