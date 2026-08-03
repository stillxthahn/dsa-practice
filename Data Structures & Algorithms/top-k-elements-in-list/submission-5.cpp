class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> freq;
        for (int &num : nums) {
            freq[num]++;
        }

        vector<int> res;

        priority_queue<pair<int, int>> pq;
        for (auto &[key, value] : freq) {
            pq.push({value, key});
        }

        while (k--) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        return res;

    }
};
