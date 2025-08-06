class Solution {
public:
    void dfs(int i,int j,vector<vector<int>>&ans,int iclr,int clr,vector<int>&r,vector<int>&c)
    {
        int n = ans.size();
        int m = ans[0].size();
        ans[i][j]=clr;
        for(int a=0;a<4;a++)
        {
            int nrow = i+r[a];
            int ncol = j+c[a];
            if(nrow>=0 && nrow<n && ncol>=0 && ncol<m && ans[nrow][ncol]==iclr){
                dfs(nrow,ncol,ans,iclr,clr,r,c);
            }
        }
    }
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        vector<vector<int>>ans=image;
        int iclr = ans[sr][sc];
        if(iclr==color) return ans;
        vector<int>r={-1,0,1,0};
        vector<int>c={0,-1,0,1};
        dfs(sr,sc,ans,iclr,color,r,c);
        return ans;
    }
};