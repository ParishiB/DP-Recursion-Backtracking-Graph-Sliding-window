class Solution {
public:
    vector<int>next_small(vector<int>&heights , int n){
        vector<int>next(n);
        stack<int>st;
        st.push(-1);
        for(int i = n-1; i >= 0 ; i--){
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            next[i] = st.top();
            st.push(i);
        }

        return next;
    }

    vector<int>prev_small(vector<int>&heights, int n){
        vector<int>prev(n);
        stack<int>st;
        st.push(-1);
        for(int i = 0; i < n ; i++){
            while(st.top() != -1 && heights[st.top()] >= heights[i]){
                st.pop();
            }
            prev[i] = st.top();
            st.push(i);
        }
        return prev;
    }

    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        vector<int>prev(n);
        vector<int>next(n);
        next = next_small(heights,n);
        prev = prev_small(heights,n);
        int area = INT_MIN;
        for(int i = 0; i < n ; i++){
            int l = heights[i];
            if(next[i] == -1)next[i] = n;
            int b = next[i] - prev[i] - 1;
            int newarea = l*b;
            area = max(area,newarea);
        }

        return area;

    }
};
