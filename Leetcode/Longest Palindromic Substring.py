class Solution:
    def longestPalindrome(self, s: str) -> str:
        if not s:
            return ""
        start,end=0,0
        n=len(s)
        for i in range(n):
            left,right=i,i
            while left>=0 and right<n and s[left]==s[right]:
                if (right-left+1)>(end-start+1):
                    start,end=left,right
                left-=1
                right+=1
            left,right=i,i+1
            while left>=0 and right <n and s[left]==s[right]:
                if (right-left+1)>(end-start+1):
                    start,end=left,right
                left-=1
                right+=1
        return s[start:end+1]
        
