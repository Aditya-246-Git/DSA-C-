class Solution {
public:
    bool winnerSquareGame(int n) {

        vector<int> dp1(n + 1, false);

        for (int i = 1; i <= n; i++) {

            for (int j = 1; j * j <= i; j++) {

                int square = j * j;

                if (!dp1[i - square]) {
                    dp1[i] = true;
                    break;
                }
            }
        }

        return dp1[n];
    }
};