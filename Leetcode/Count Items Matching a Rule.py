class Solution:
    def countMatches(self, items: list[list[str]], ruleKey: str, ruleValue: str) -> int:
        if ruleKey=="type":
            idx=0
        elif ruleKey=="color":
            idx=1
        else:
            idx=2
        return sum(1 for item in items if item[idx]==ruleValue)
        
