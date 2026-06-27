class Solution {
public:
    int countK(vector<int>& nums, int num){
        int m = 1;
        long long p = 0;
        for(int i = 0; i<nums.size(); i++){
            if(p + nums[i]<= num){
                p += nums[i];
            }
            else{
                m +=1;
                p = nums[i];
            }
        }
        return m;
    }
    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        if(k>n) return -1;
        int low = *max_element(nums.begin(), nums.end());
        int high = accumulate(nums.begin(), nums.end(), 0);
        while(low<=high){
            int mid = (low+high)/2;
            int m = countK(nums,mid);
            if(m>k){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }
        return low;
        
    }
};