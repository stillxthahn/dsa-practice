class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n = heights.size();
        // sort(heights.begin(), heights.end(), cmp);
        int l = 0, r = n - 1;
        int res = 0;
        while (l < r) {
            res = max(res, min(heights[l], heights[r]) * (r - l));
            if (heights[l] < heights[r]) {
                l++;
            }
            else r--;
        }
        return res;
    }
};
