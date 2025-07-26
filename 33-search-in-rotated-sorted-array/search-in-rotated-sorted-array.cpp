class Solution {
public:
    int search(vector<int>& nums, int tar) {
        int l=0,h=nums.size()-1;
        while(l<=h)
        {
            int m = (l+h)/2;
            if(nums[m]==tar) return m;
            if(nums[l]<=nums[m])
            {
                if(nums[l]<=tar && nums[m]>=tar)
                {
                    h=m-1;
                }
                else{
                    l=m+1;
                }
            }
            else{
                if(nums[m]<=tar && nums[h]>=tar)
                {
                    l=m+1;
                }
                else{
                    h=m-1;
                }
            }
        }
        return -1;
    }
};