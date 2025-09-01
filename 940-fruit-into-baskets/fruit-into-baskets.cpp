class Solution {
public:
    int totalFruit(vector<int>& f) {
        int i=0,j=0;
        unordered_map<int,int>um;
        int ans=0;
        while(j<f.size())
        {
            um[f[j]]++;
            while(um.size()>2)
            {
                um[f[i]]--;
                if(um[f[i]]==0)um.erase(f[i]);
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans;
    }
};