class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<pair<int,int>,int>>q;
        vector<vector<int>> vis(n, vector<int>(m, 0));
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j]=2;
                }
                else vis[i][j]=0;
            }
        }
        int tm=0;
        vector<int>nrow={-1,0,1,0};
        vector<int>ncol={0,-1,0,1};
        while(q.size()!=0)
        {
            int r = q.front().first.first;
            int c = q.front().first.second;
            int t=q.front().second;
            tm=max(tm,t);
            q.pop();
            for(int a=0;a<4;a++)
            {
                int r1=r+nrow[a];
                int c1=c+ncol[a];
                if(r1>=0 && r1<n && c1>=0 && c1<m && grid[r1][c1]==1 && vis[r1][c1]!=2)
                {
                    q.push({{r1,c1},t+1});
                    vis[r1][c1]=2;
                }
            }
        }
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(grid[i][j]==1 && vis[i][j]!=2) return -1;
            }
        }
        return tm;
    }
};