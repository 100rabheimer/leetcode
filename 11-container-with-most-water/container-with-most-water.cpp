class Solution {
public:
    int maxArea(vector<int>& height) {
        


        int left = 0;
        int right = height.size() - 1;

        int ans = 0;

        while (left < right) {

            // Current width
            int width = right - left;

            // Water ki height chhoti wall decide karegi
            int h = min(height[left], height[right]);

            // Maximum area update
            ans = max(ans, width * h);

            // Chhoti wall ko move karo
            // Badi wall ko move karne se width kam hogi
            // aur height improve nahi hogi.
            if (height[left] < height[right])
                left++;
            else
                right--;
        }

        return ans;
    }
};