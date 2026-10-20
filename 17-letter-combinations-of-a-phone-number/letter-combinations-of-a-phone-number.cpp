class Solution {
public:
vector<string>mp={
" ", " ", "abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"
};
vector<string>ans;
void solve(int index, string& digits, string& path){
    if(index==digits.size()){
        ans.push_back(path);
        return;
    }

    string letters=mp[digits[index]-'0'];
    for(char ch: letters){
        path.push_back(ch);
        solve(index+1,digits,path);
        path.pop_back();
    }
}
    vector<string> letterCombinations(string digits) {
if(digits.empty())    {
    return {};
}    
string path="";
solve(0,digits,path);
return ans;
    }
};