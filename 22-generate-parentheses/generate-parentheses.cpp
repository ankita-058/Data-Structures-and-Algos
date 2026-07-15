class Solution {
public:
    void func(string curr, int open, int close, int n, vector<string>& res){
        if(curr.length() == 2*n){
            res.push_back(curr);
            return;
        }
        if(open < n) func(curr + '(', open + 1, close, n, res);
        if(close < open) func(curr + ')', open, close + 1, n, res);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        func("", 0, 0, n, res);
        return res;
    }
};