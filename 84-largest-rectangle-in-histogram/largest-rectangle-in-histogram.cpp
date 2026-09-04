class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int>st;
              int maxarea = 0;

        for(int i=0;i<heights.size();i++){
            while(!st.empty() && heights[i]<heights[st.top()]){
                int index=st.top();
                st.pop();
                int left;
                if(st.empty()){
                    left=-1;

                }else{
                    left=st.top();
                }
                   int right = i;

                int width = right - left - 1;

                int area = heights[index] * width;

                maxarea = max(area, maxarea);
            }

            st.push(i);

            }

            //remaining bars have no smaller elements on the right
            while(!st.empty()){
                int index=st.top();
                st.pop();
                int left;
                if(st.empty()){
                     left=-1;

                }else{
                    left=st.top();
                }
                  int right = heights.size();

            int width = right - left - 1;

            int area = heights[index] * width;

            maxarea = max(area, maxarea);
            }
 return maxarea;
        
    }
};