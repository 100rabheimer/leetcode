class Solution {
public:
    string largestNumber(vector<int>& nums) {
        vector<string>arr;
        for(int i=0;i<nums.size();i++){
            arr.push_back(to_string(nums[i]));
        }

        sort(arr.begin(), arr.end(),[](string a, string b){return a+b>b+a;});
// string conacatenation
string ans="";
for(int i=0;i<arr.size();i++){
    ans+=arr[i];
}
// if final ans ka first character 0 hai toh 0 return 
if(ans[0]=='0')return "0";

return ans;
    }

};