class Solution {
public:
    const int INF = 1e9;

    vector<vector<vector<int>>> dp;
    vector<int> prefix;
    int K;

    int solve(int i, int j, int p) {

        // 1. Impossible state
        if(j - i + 1 < p)
            return INF;

        // 2. Base case
        if(i == j) {
            if(p == 1) return 0;
            return INF;
        }

        // 3. Memoization check
        if(dp[i][j][p] != -1)
            return dp[i][j][p];

        // 4. Convert interval into exactly 1 pile
        if(p == 1) {
            return dp[i][j][p] =
                solve(i, j, K) + prefix[j + 1] - prefix[i];
        }

        // 5. Convert interval into p piles
        int ans = INF;

        for(int mid = i; mid < j; mid += K - 1) {

            int left = solve(i, mid, 1);
            int right = solve(mid + 1, j, p - 1);

            if(left == INF || right == INF)
                continue;

            ans = min(ans, left + right);
        }

        return dp[i][j][p] = ans;
    }

    int mergeStones(vector<int>& stones, int k) {

        int n = stones.size();
        K = k;

        // 6. Feasibility check
        if((n - 1) % (K - 1) != 0)
            return -1;

        // 7. Prefix sum
        prefix.assign(n + 1, 0);

        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + stones[i];
        }

        // 8. Initialize 3D DP
        dp.assign(n,
            vector<vector<int>>(
                n, vector<int>(K + 1, -1)
            )
        );

        return solve(0, n - 1, 1);
    }
};