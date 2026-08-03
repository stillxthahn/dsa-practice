class Solution {
public:
    static bool cmp(int &a, int &b) {
        return a < b;
    }
    bool hasDuplicate(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end(), cmp);
        for (int i = 1; i < n; i++) {
            if (nums[i] == nums[i - 1]) return true;
        }
        return false;
    }
};