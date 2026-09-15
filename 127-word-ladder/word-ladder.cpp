class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {

        // Queue stores:
        // {current word, number of steps taken to reach it}
        queue<pair<string, int>> q;

        // Put all words into set for O(1) average lookup
        unordered_set<string> st(wordList.begin(), wordList.end());

        // Start BFS from beginWord
        // beginWord itself counts as step 1
        q.push({beginWord, 1});

        // We have already used beginWord,
        // so remove it from the set
        st.erase(beginWord);

        // BFS
        while (!q.empty()) {

            // Get current word and its step count
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();

            // If we reached endWord, return the number of steps
            if (word == endWord) {
                return steps;
            }

            // Try changing every character of the current word
            for (int i = 0; i < word.size(); i++) {

                // Save the original character
                char original = word[i];

                // Try every possible lowercase letter
                for (char ch = 'a'; ch <= 'z'; ch++) {

                    // Change character at index i
                    word[i] = ch;

                    // Check whether this newly formed word
                    // exists in the word list
                    if (st.find(word) != st.end()) {

                        // Remove it immediately so that
                        // we don't visit the same word again
                        st.erase(word);

                        // Add the valid word to the queue
                        // with one more step
                        q.push({word, steps + 1});
                    }
                }

                // Restore the original character
                // before moving to the next index
                word[i] = original;
            }
        }

        // If endWord cannot be reached
        return 0;
    }
};