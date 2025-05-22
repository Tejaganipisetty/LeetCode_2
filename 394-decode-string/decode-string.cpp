class Solution {
public:
    string decodeString(string s) {
        stack<int>nums;
        stack<string>str;
        int num=0;
        string st1="";
        for(auto x:s)
        {
            if(x>='0' && x<='9') num=num*10+x-'0';
            else if(x=='[') {
                nums.push(num);
                str.push(st1);
                num=0;
                st1="";
            }
            else if(x==']'){
                string st2 = str.top();
                str.pop();
                int val = nums.top();
                nums.pop();
                while(val--) st2+=st1;
                st1=st2;
            }
            else{
                st1+=x;
            }
        }
        return st1;
    }
};