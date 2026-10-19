class Solution:
    def uniqueOccurrences(self, arr: list[int]) -> bool:
        n=[]
        r=[]
        for i in arr:
            if i not in n:
                n.append(i)
                c=0
                for j in arr:
                    if i==j:
                        c+=1            
                r.append(c)
        res=list(set(r))
        if len(res)==len(r):
            return True
        return False
        
        

        
        
            

        

        
