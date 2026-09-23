class Solution:
    def containsDuplicate(self, nums: list[int]) -> bool:
        num_set=set(nums)
        if len(nums)==len(num_set):
            return False
        return True
        
