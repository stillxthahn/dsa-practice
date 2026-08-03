class Solution:
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = {}
        for str in strs:
            encoded_list = [0] * 26
            for l in str:
                index = ord(l) - ord('a')
                encoded_list[index] += 1
            if tuple(encoded_list) not in ans.keys():
                ans[tuple(encoded_list)] = []    
            ans[tuple(encoded_list)].append(str)    
        
        return list(ans.values())
            