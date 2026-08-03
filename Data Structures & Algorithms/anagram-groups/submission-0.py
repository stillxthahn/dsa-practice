class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = {}

        for str in strs:
            sorted_str = "".join(sorted(str))
            if sorted_str not in ans.keys():
                ans[sorted_str] = []
            ans[sorted_str].append(str)
        
        return list(ans.values())
            