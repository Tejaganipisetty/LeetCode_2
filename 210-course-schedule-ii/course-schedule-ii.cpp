class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& pre) {
        vector<vector<int>>adj(numCourses);
        queue<int>q;
        vector<int>ans;
        for(auto x:pre)
        {
            adj[x[1]].push_back(x[0]);
        }
        vector<int>inDegree(numCourses);
        for(int i=0;i<numCourses;i++)
        {
            for(auto x:adj[i])
            {
                inDegree[x]++;
            }
        }
        for(int i=0;i<numCourses;i++)
        {
            if(inDegree[i]==0) q.push(i);
        }
        while(q.size()!=0)
        {
            int val = q.front();
            ans.push_back(val);
            q.pop();
            for(auto x:adj[val])
            {
                inDegree[x]--;
                if(inDegree[x]==0) q.push(x);
            }
        }
        if(ans.size()==numCourses) return ans;
        return {};
    }
};