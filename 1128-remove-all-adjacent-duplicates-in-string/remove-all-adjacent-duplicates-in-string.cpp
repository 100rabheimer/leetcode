class Solution {
public:
    string removeDuplicates(string s) {
        //1.ek stack bnayenge 
        stack<char>st;

        //for loop chlayenge aus agar stack empty mhi hai and top element string ke ith element ke equal hai toh usko pop kr denge ya pghir yeh sb nhi match ho rha toh stack mein push kr denge 
        for(int i=0;i<s.size();i++){
            if(!st.empty() && st.top()==s[i]){
                st.pop();
            }else{
                st.push(s[i]);
            }
        }

        // stack mein elements be like [c,a] and isko ab output mein dena hai toh hm kya krenge ki ans naam ki string bnayenge aur usme elements dalenge stack ke top wale be like ans="c then a"="ca"  aur top element string mein daalke usko pop kr denge jisse ki stack ka top change ho jaye 
        string ans="";
        while(!st.empty()){
            ans+=st.top();
            st.pop();
        }
        // ab ans wali string aa gyi hai toh usko sidha krbne ke liye reverse kr denge shuru se end tk ke liye 
        reverse(ans.begin(),ans.end());
        return ans;
    }
};