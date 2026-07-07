class Solution {
public:

    // Check karta hai ki given day tak
    // m bouquets ban sakte hain ya nahi.
    bool canMake(vector<int>& bloomDay, int day, int m, int k)
    {
        int flowers = 0;
        int bouquets = 0;

        for(int bloom : bloomDay)
        {
            if(bloom <= day)
            {
                flowers++;
            }
            else
            {
                // Chain break
                flowers = 0;
            }

            // k adjacent flowers mil gaye
            if(flowers == k)
            {
                bouquets++;

                // Ye flowers use ho gaye
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k)
    {
        // Total flowers hi kam hain
        if((long long)m * k > bloomDay.size())
            return -1;

        int low = *min_element(bloomDay.begin(), bloomDay.end());

        int high = *max_element(bloomDay.begin(), bloomDay.end());

        int ans = -1;

        while(low <= high)
        {
            int mid = low + (high-low)/2;

            if(canMake(bloomDay, mid, m, k))
            {
                ans = mid;

                // Aur chhota day try karo
                high = mid - 1;
            }
            else
            {
                // Day kam hai
                low = mid + 1;
            }
        }

        return ans;
    }
};