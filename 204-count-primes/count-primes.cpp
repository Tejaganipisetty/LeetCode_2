class Solution {
public:
    int countPrimes(int n) {
        if(n==0 || n==1) return 0;
        vector<int>prime(n+1,0);
        int cnt=0;
        for(int i=2;i*i<n;i++)
        {
            if(prime[i]==0)
            {
                for(int j=i*i;j<n;j+=i) prime[j]=1;
            }
        }
        for(int i=2;i<n;i++) if(prime[i]==0) cnt++;
        return cnt;
    }
};