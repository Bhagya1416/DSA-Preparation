class Solution:
    def sumOfUnique(self, nums: list[int]) -> int:
        t=0
        for i in range(len(nums)):
            c=0
            for j in range(len(nums)):
                if nums[i]==nums[j]:
                    c+=1
            if c==1:
                t+=nums[i]
        return t
            
        
