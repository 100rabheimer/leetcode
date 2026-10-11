class Solution {
public:
bool ispalindrome(string& s, int start, int end){
    while(start<end){
        if(s[start]!=s[end]){
            return false;
        }
        start++;
        end--;
    }
    return true;
}
void solve(string& s, int start, vector<string>& path, vector<vector<string>>& ans){
    if(start==s.size()){
        ans.push_back(path);
        return;
    }
    //explore all possible partitions
    for(int i=start;i<s.size();i++){
        //check whether the s[start....i] is a palindrome
        if(ispalindrome(s,start,i)){
            //choose
            path.push_back(s.substr(start,i-start+1));
            //explore remaining string
            solve(s,i+1,path,ans);
            path.pop_back();
        }
    }
}

    vector<vector<string>> partition(string s) {
        vector<vector<string>>ans;
        vector<string>path;
        solve(s,0,path,ans);
        return ans;
    }
};