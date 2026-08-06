class Solution:
    def letterCombinations(self, digits: str) -> List[str]:
        if not digits:
            return []
        digit_to_letters={
            "2":"abc","3":"def","4":"ghi","5":"jkl","6":"mno","7":"pqrs","8":"tuv","9":"wxyz"
        }
        result=[]
        def backtrack(index:int,path:list):
            if len(path)==len(digits):
                result.append("".join(path))
                return
            current_digit=digits[index]
            letters=digit_to_letters[current_digit]
            for letter in letters:
                path.append(letter)
                backtrack(index+1,path)
                path.pop()
        backtrack(0,[])
        return result
        
