class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<int> prev(amount + 1, 0), cur(amount + 1, 0);
        for(int t = 0; t <= amount; t++){
            if(t % coins[0] == 0) prev[t] = t/coins[0];
            else prev[t] = 1e9;
        }
        for(int ind = 1; ind<n; ind++){
            for(int t = 0; t <= amount; t++){
                int nottake = 0 + prev[t];
                int take = INT_MAX;
                if(coins[ind] <= t){
                    take = 1 + cur[t - coins[ind]];
                }
                cur[t] = min(take, nottake);
            }
            prev = cur;
        }
        int ans = prev[amount];
        if(ans >= 1e9) return -1;
        return ans;
    }
};