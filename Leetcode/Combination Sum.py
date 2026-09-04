class Solution:
    def combinationSum(self, candidates: List[int], target: int) -> List[List[int]]:
        res=[]
        def backtrack(remain,combo,start):
            if remain==0:
                res.append(list(combo))
                return
            if remain <0:
                return
            for i in range(start,len(candidates)):
                combo.append(candidates[i])
                backtrack(remain-candidates[i],combo,i)
                combo.pop()
        backtrack(target,[],0)
        return res

        
