class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int maxlength = 0;
int left = 0;

map<char, int> mp;

for (int right = 0; right < s.size(); right++) {

    mp[s[right]]++;

    while (mp[s[right]] > 1) {

        mp[s[left]]--;
        left++;
    }

    maxlength = max(maxlength, right - left + 1);
}

return maxlength;
    }
};