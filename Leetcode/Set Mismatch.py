class Solution:
    def findErrorNums(self, nums: list[int]) -> list[int]:
        n=len(nums)
        c=[0]*(n+1)
        for i in nums:
            c[i]+=1
        d=-1
        m=-1
        for i in range(1,n+1):
            if c[i]==2:
                d=i
            elif c[i]==0:
                m=i
        return [d,m]        

        
