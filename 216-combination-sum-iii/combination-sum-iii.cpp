class Solution {
public:
    void func(int sum, int last, vector<int>& nums, int k, vector<vector<int>>& ans){
        if(sum == 0 && nums.size() == k){
            ans.push_back(nums);
            return;
        }
        if(sum <= 0 || nums.size() > k) return;
        for(int i = last; i <= 9; i++){
            if(i <= sum){
                nums.push_back(i);
                func(sum - i, i + 1, nums, k, ans);
                nums.pop_back();
            }
            else{
                break;
            }
        }
    }
    
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> nums;
        func(n, 1, nums, k, ans);
        return ans;
    }
};