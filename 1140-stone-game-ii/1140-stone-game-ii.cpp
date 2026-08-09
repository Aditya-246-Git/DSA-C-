class Solution {
public:
    int f(int i, int M, vector<int>& piles,vector<vector<int>> &dp) {
        int n = piles.size();
        if (i >= n)
            return 0;
        if(dp[i][M]!=-1) return dp[i][M];
        int total = 0;
        for (int j = i; j < n; j++) {
            total += piles[j];
        }
        int ans = 0;
        for (int X = 1; X <= 2 * M && i + X <= n; X++) {
            int opponent = f(i + X, max(M, X), piles,dp);
            int current = total - opponent;

            ans = max(ans, current);
        }
        return dp[i][M]=ans;
    }
    int stoneGameII(vector<int>& piles) {
        int n=piles.size();
        vector<vector<int>> dp(n, vector<int>(n + 1, -1));
        return f(0, 1, piles,dp);
    }
};