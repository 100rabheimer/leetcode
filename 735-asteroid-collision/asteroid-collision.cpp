class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int current :asteroids){
            bool alive=true;
            while(alive && current<0 && !st.empty() && st.top()>0){
                if(abs(current)>st.top()){
                    st.pop();
                }else if(abs(current)==st.top()){
                    st.pop();
                    alive=false;
                }
                else{
                    alive=false;
                }
            }
            if(alive){
                st.push(current);
            }
        }
       vector<int>ans;
       while(!st.empty()){
        ans.push_back(st.top());
        st.pop();
       }
       reverse(ans.begin(),ans.end());
       return ans;
    }
};