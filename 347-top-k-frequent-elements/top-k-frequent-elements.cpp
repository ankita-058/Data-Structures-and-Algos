class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
       unordered_map<int,int> freqmp;
       for(int num : nums){
         freqmp[num]++;
       }
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> minH;

       for(auto& entry : freqmp){
         minH.push({entry.second, entry.first});
         if(minH.size() > k){
            minH.pop();
          }
       }
       vector<int> result;
       while(!minH.empty()){
         result.push_back(minH.top().second);
         minH.pop();
       }
       return result;
    }
};