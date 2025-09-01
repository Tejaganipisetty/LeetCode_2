class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int>ans,a(26,0),b(26,0);
        int i=0,j=0;
        for(auto x:p) a[x-'a']++;
        while(j<s.size())
        {
            int len=j-i+1;
            b[s[j]-'a']++;
            if(len<p.size())j++;
            else if(len==p.size())
            {
               if(a==b) ans.push_back(i);
               b[s[i]-'a']--;
               i++;
               j++;
            }
        }
        return ans;
    }
};