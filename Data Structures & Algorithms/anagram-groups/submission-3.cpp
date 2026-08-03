class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;

        unordered_map<string, vector<string>> mp;

        for (int i = 0; i < strs.size(); i++) {
            string s = strs[i];
            sort(s.begin(), s.end());

            string key = "";
            for (char c : s) {
                key += '#' + c;
            }
            mp[key].push_back(strs[i]);
        }

        for (auto &[key, value] : mp) {
            res.push_back(value);
        }
        return res;
    }
};
