class Solution {
public:
    bool isNStraightHand(vector<int>& hand, int groupSize) {
        if(hand.size() % groupSize != 0) return false;
        map<int,int> count;
        for(int card : hand) count[card]++;
        for(auto [card, freq] : count){
            if(freq > 0){
                for(int i = 0; i <groupSize; i++){
                    if(count[card + i] < freq) return false;
                    count[card + i] -= freq;
                }
            }
        }
        return true;
    }
};