class Solution:
    def fun(self,n,l):
        if n==1 or n==2:return n
        if l[n]!=-1:return l[n]
        l[n]=self.fun(n-1,l)+self.fun(n-2,l)
        return l[n]
    def climbStairs(self, n: int) -> int:
        l=[-1]*(n+1)
        return self.fun(n,l)
        
        