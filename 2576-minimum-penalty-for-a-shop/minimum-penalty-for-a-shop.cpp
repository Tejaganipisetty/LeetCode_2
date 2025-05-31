class Solution {
public:
    int bestClosingTime(string cust) {
        int pen=0;
        for(auto x:cust) pen++;
        int minpen=pen;
        int ans=0;
        for(int i=0;i<cust.size();i++)
        {
            if(cust[i]=='Y') pen--;
            else pen++;
            if(pen<minpen)
            {
                minpen=pen;
                ans=i+1;
            }
        }
        return ans;
    }
};