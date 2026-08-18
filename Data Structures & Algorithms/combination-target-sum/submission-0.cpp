class Solution {
public:
    vector<vector<int>> res;
    vector<vector<int>> combinationSum(vector<int>& nums, int target) {
        vector<int> output;
        int sum = 0;
        backtracking(nums, target, output, sum, 0);
        return res;
    }

    void backtracking(vector<int> &nums, int target, vector<int> &output, int sum, int idx) {
        if (sum == target) {
            res.push_back(output);
        }
        if (sum > target) return;

        for (int i = idx; i < nums.size(); i++) {
            output.push_back(nums[i]);
            backtracking(nums, target, output, sum + nums[i], i);
            output.pop_back();
        }
    }
};
