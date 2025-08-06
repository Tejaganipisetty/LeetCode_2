class Solution {
public:
    int romanToInt(string s) {
       int ans=0;
       unordered_map<char,int>um={{'I',1},{'V',5},{'X',10},
       {'L',50},{'C',100},{'D',500 },{'M',1000}};
       for(int i=0;i<s.size();i++)
       {
        if(i+1<s.size() && um[s[i]]<um[s[i+1]]) ans-=um[s[i]];
        else ans+=um[s[i]];
       }
       return ans;
    }
};