class Solution:
    def isPalindrome(self, s: str) -> bool:
        st=""
        for x in s:
            x=x.lower()
            if x>='a' and x<='z' or x>='0' and x<='9':
                st+=x
        if(st==st[::-1]) :return True
        return False
        