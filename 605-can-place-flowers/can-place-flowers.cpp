class Solution {
public:
    bool canPlaceFlowers(vector<int>& f, int n) {
        if(n==0) return true;
        for(int i=0;i<f.size();i++)
        {
           if(f[i]==0)
           {
             bool a = (i==0) || (f[i-1]==0);
             bool b = (i==f.size()-1) || (f[i+1]==0);
             if(a && b)
             {
              f[i]=1;
              n--;
              if(n==0) return true;
             }
           }
           
        }
        return n==0;
    }
};