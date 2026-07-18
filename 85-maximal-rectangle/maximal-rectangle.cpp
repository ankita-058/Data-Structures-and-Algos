class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int maxA = 0;
        int n = heights.size();
        heights.push_back(0);
        for(int i=0; i<=n; i++){
            while(!st.empty() && heights[st.top()] > heights[i]){
                int height = heights[st.top()];
                st.pop();
                int width = st.empty() ? i : i - st.top() - 1;
                
                maxA = max(maxA, width * height);
            }
            st.push(i);
        }
        return maxA;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        if(matrix.empty()) return 0;
        int m = matrix[0].size();
        vector<int> height(m, 0);
        int maxA = 0;
        for(auto& row:matrix){
            for(int i = 0; i<m; i++){
                if(row[i] == '1') height[i]++;
                else height[i] = 0;
            }
            maxA = max(maxA, largestRectangleArea(height));
        }
        return maxA;
    }
};