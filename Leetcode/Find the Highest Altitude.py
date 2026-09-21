class Solution:
    def largestAltitude(self, gain: list[int]) -> int:
        max=0
        current=0
        for i in gain:
            current+=i
            if current>max:
                max=current
        return max
        
