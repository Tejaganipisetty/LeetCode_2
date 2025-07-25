class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string,vector<string>>um;
        for(auto x:strs)
        {
            string s = x;
            sort(s.begin(),s.end());
            um[s].push_back(x);
        }
        for(auto [x,y]:um) ans.push_back(y);
        return ans;
    }
};