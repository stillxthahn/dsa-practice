class Solution:
    def hasDuplicate(self, nums: List[int]) -> bool:
        sorted_list = sorted(nums)
        for i in range(0, len(sorted_list) - 1):
            if sorted_list[i] == sorted_list[i + 1]:
                return True
        return False
