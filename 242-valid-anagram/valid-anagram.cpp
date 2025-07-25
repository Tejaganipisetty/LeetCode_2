class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char,int>um1,um2;
        for(auto x:s)um1[x]++;
        for(auto x:t)um2[x]++;
        if(um1==um2)return true;
        return false;
    }
};