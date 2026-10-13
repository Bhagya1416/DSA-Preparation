class Solution:
    def plusOne(self, digits: list[int]) -> list[int]:
        c=0
        for i in digits:
            c=c*10+i
        r=c+1
        return list(map(int,str(r)))
        
