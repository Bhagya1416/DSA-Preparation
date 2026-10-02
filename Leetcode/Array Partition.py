class Solution:
    def arrayPairSum(self, nums: List[int]) -> int:
        nums.sort()
        r=0
        for i in range(len(nums)):
            if i%2==0:
                r+=nums[i]
        return r


        
