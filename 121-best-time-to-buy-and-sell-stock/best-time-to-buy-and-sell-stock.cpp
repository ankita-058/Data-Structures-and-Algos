class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int mini = prices[0];
        int maxProf = 0;
        int n = prices.size();
        for(int i =0; i<n; i++){
            int cost = prices[i]-mini;
            maxProf= max(maxProf, cost);
            mini= min(mini, prices[i]);
        }
        return maxProf;
    }
};