class Solution {
public:
    bool backspaceCompare(string s, string t) {
        
        stack<char> st1;
        stack<char> st2;

        // Process string s
        for(int i = 0; i < s.size(); i++) {
            
            if(s[i] != '#') {
                st1.push(s[i]);
            }
            
            else if(!st1.empty()) {
                st1.pop();
            }
        }

        // Process string t
        for(int i = 0; i < t.size(); i++) {
            
            if(t[i] != '#') {
                st2.push(t[i]);
            }
            
            else if(!st2.empty()) {
                st2.pop();
            }
        }

        // Different sizes => strings cannot be equal
        if(st1.size() != st2.size()) {
            return false;
        }

        // Compare characters
        while(!st1.empty()) {
            
            if(st1.top() != st2.top()) {
                return false;
            }

            st1.pop();
            st2.pop();
        }

        return true;
    }
};