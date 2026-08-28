class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxIn = 0;
        for(int i = 0; i < nums.size(); i++){
            if(i > maxIn){
                return false;
            }
            maxIn = max(maxIn, i + nums[i]);
        }
        return true;
    }
};