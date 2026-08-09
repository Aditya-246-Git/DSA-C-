class Solution {
public:

    int stoneGameII(vector<int>& piles) {

        int n = piles.size();

        // suffix[i] = stones from i to n-1
        vector<int> suffix(n + 1, 0);

        for (int i = n - 1; i >= 0; i--) {
            suffix[i] = suffix[i + 1] + piles[i];
        }

        // dp[i][M]
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, 0));

        // i = n is already 0
        // dp[n][M] = 0

        for (int i = n - 1; i >= 0; i--) {

            for (int M = n; M >= 1; M--) {

                int ans = 0;

                for (int X = 1; X <= 2 * M && i + X <= n; X++) {

                    int opponent = dp[i + X][max(M, X)];

                    int current = suffix[i] - opponent;

                    ans = max(ans, current);
                }

                dp[i][M] = ans;
            }
        }

        return dp[0][1];
    }
};
