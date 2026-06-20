class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        double maxProd = INT_MIN;
        double left = 1;
        double right = 1;
        
        for (int i = 0; i < n; i++) {
            if (left == 0) left = 1;
            if (right == 0) right = 1;
            left *= (double)nums[i];
            right *= (double)nums[n - 1 - i];
            maxProd = max(maxProd, max(left,right ));
        }
        
        return (int)maxProd;
        
    }
};