class Solution {
public:

    int start = 0;      // Longest palindrome ka starting index
    int maxLen = 0;     // Longest palindrome ki length

    void expand(string &s, int left, int right)
    {
        // Jab tak palindrome mil raha hai, expand karte jao
        while (left >= 0 &&
               right < s.size() &&
               s[left] == s[right])
        {
            int currLen = right - left + 1;

            // Agar current palindrome bada hai,
            // to answer update kar do
            if (currLen > maxLen)
            {
                maxLen = currLen;
                start = left;
            }

            // Bahar expand karo
            left--;
            right++;
        }
    }

    string longestPalindrome(string s)
    {
        for (int i = 0; i < s.size(); i++)
        {
            // Odd length palindrome
            expand(s, i, i);

            // Even length palindrome
            expand(s, i, i + 1);
        }

        // Longest palindrome return karo
        return s.substr(start, maxLen);
    }
};