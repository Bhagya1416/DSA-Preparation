class Solution:
    def solveSudoku(self, board: List[List[str]]) -> None:
        rows=[set() for _ in range(9)]
        cols=[set() for _ in range(9)]
        boxes=[set() for _ in range(9)]
        for r in range(9):
            for c in range(9):
                val=board[r][c]
                if val!='.':
                    rows[r].add(val)
                    cols[c].add(val)
                    box_idx=(r//3)*3+(c//3)
                    boxes[box_idx].add(val)
        def backtrack(r:int,c:int)->bool:
            if c==9:
                r+=1
                c=0
                if r==9:
                    return True
                if board[r][c]!='.':
                    return backtrack(r,c+1)
                box_idx=(r//3)*3+(c//3)
                for digit in "123456789":
                    if(digit not in rows[r] and digit not in cols[c] and digit not in boxes[box_idx]):
                        board[r][c]=digit
                        rows[r].add(digit)
                        cols[c].add(digit)
                        if backtrack(r,c+1):
                            return True
                        board[r][c]='.'
                        rows[r].remove(digit)
                        cols[c].remove(digit)
                        boxes[box_idx].remove(digit)
                return False
            backtrack(0,0)       
