class Solution {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<unsigned int> prev(amount+1, 0), cur(amount+1, 0);
        for(int t = 0; t<=amount; t++){
            prev[t] = (t % coins[0] == 0) ? 1:0;
        }
        for(int ind = 1; ind<n; ind++){
            for(int t = 0; t<=amount; t++){
                unsigned int nottake = prev[t];
                unsigned int take = 0;
                if(coins[ind] <= t){
                    take = cur[t - coins[ind]];
                }
                cur[t] = take + nottake;
            }
            prev = cur;
        }
        return prev[amount];
    }
};