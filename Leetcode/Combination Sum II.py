class Solution:
    def combinationSum2(self, candidates: List[int], target: int) -> List[List[int]]:
        res=[]
        candidates.sort()
        def backtrack(start:int,current_target:int,path:List[int]):
            if current_target==0:
                res.append(list(path))
                return
            for i in range(start,len(candidates)):
                if i>start and candidates[i]==candidates[i-1]:
                    continue
                if candidates[i]>current_target:
                    break
                path.append(candidates[i])
                backtrack(i+1,current_target-candidates[i],path)
                path.pop()
        backtrack(0,target,[])
        return res
        
