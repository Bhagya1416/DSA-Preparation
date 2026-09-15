class Solution:
    def selfDividingNumbers(self, left: int, right: int) -> List[int]:
        a=[]
        for i in range(left,right+1):
            temp=i
            is_self=True
            while temp>0:
                digit=temp%10
                if digit==0 or i%digit!=0:
                    is_self=False
                    break
                temp//=10
            if is_self:
                a.append(i)
        return a
            
            

            
        
