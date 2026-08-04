class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st(nums.begin(), nums.end());

        int res = 0;
        for (int num : st) {
            // num is the starting point if cannot find num - 1 in set
            if (st.find(num - 1) == st.end()) {
                int length = 1;
                while (st.find(num + length) != st.end()) {
                    length++;
                }
                res = max(res, length);
            }
        }
        return res;
    }
};
