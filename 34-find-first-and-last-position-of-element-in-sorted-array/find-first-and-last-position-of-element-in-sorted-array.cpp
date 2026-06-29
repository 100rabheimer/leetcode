class Solution {
public:
 // First Occurrence nikalne wala function
    int firstOccurrence(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        // Agar target na mile to -1 return hoga
        int ans = -1;

        while(low <= high)
        {
            // Middle index nikalo
            int mid = low + (high - low) / 2;

            // Target mil gaya
            if(nums[mid] == target)
            {
                ans = mid;          // Current answer save kar lo

                // Ho sakta hai left me bhi target ho
                // Isliye left side search karo
                high = mid - 1;
            }

            // Mid chhota hai target se
            else if(nums[mid] < target)
            {
                // Target sirf right side ho sakta hai
                low = mid + 1;
            }

            // Mid bada hai target se
            else
            {
                // Target left side me hoga
                high = mid - 1;
            }
        }

        return ans;
    }

    // Last Occurrence nikalne wala function
    int lastOccurrence(vector<int>& nums, int target)
    {
        int low = 0;
        int high = nums.size() - 1;

        int ans = -1;

        while(low <= high)
        {
            int mid = low + (high - low) / 2;

            if(nums[mid] == target)
            {
                ans = mid;          // Answer save karo

                // Ho sakta hai right me bhi target ho
                // Isliye right side search karo
                low = mid + 1;
            }

            else if(nums[mid] < target)
            {
                low = mid + 1;
            }

            else
            {
                high = mid - 1;
            }
        }

        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
     
        int first = firstOccurrence(nums, target);
        int last = lastOccurrence(nums, target);

        return {first, last};
    }
};