class Solution {
public:
    int fp(vector<int>&nums,int target)
    {
        int ans=-1;
        int l=0,h=nums.size()-1;
        while(l<=h)
        {
           int m = (l+h)/2;
           if(nums[m]==target){
              ans=m;
              h=m-1;
           }
           else if(nums[m]<target) l=m+1;
           else h=m-1;
        }
        return ans;
    }
    int lp(vector<int>&nums,int target)
    {
        int ans=-1;
        int l=0,h=nums.size()-1;
        while(l<=h)
        {
           int m = (l+h)/2;
           if(nums[m]==target){
              ans=m;
              l=m+1;
           }
           else if(nums[m]<target) l=m+1;
           else h=m-1;
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        vector<int>v(2);
        v[0]=fp(nums,target);
        v[1]=lp(nums,target);
        return v;
    }
};