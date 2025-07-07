class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& v) {
        vector<vector<int>>ans;
        sort(v.begin(),v.end());
        for(int  i=0;i<v.size();i++)
        {
           if(ans.empty() || ans.back()[1]<v[i][0]) ans.push_back(v[i]);
           else ans.back()[1]=max(ans.back()[1],v[i][1]); 
        }
        return ans;
    }
};