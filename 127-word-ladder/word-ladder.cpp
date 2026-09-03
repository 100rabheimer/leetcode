class Solution {
public:
    int ladderLength(string beginWord, string endWord,
                     vector<string>& wordList) {

        // Step 1: wordList ko set mein store karte hain
        // taaki kisi word ko quickly check kar sakein
        unordered_set<string> dict(wordList.begin(), wordList.end());

        // Agar endWord dictionary mein hi nahi hai,
        // toh transformation possible nahi hai
        if(dict.find(endWord) == dict.end())
            return 0;


        // Step 2: BFS queue
        queue<string> q;
        q.push(beginWord);


        // Step 3: visited words
        // beginWord ko already discover kar liya
        unordered_set<string> visited;
        visited.insert(beginWord);


        // beginWord khud sequence ka first word hai
        int count = 1;


        // Step 4: BFS
        while(!q.empty()) {

            // Current BFS level ke words
            int size = q.size();

            for(int j = 0; j < size; j++) {

                string word = q.front();
                q.pop();


                // Destination mil gaya
                if(word == endWord)
                    return count;


                // Step 5: Current word ke neighbours generate karo
                for(int i = 0; i < word.size(); i++) {

                    // Har possible character try karo
                    for(char ch = 'a'; ch <= 'z'; ch++) {

                        // Same character lagane ka koi point nahi
                        if(ch == word[i])
                            continue;


                        // Original word ko preserve karne ke liye copy
                        string temp = word;

                        // Sirf ek character change
                        temp[i] = ch;


                        // Kya valid word hai?
                        // Aur kya pehle visit nahi hua?
                        if(dict.find(temp) != dict.end() &&
                           visited.find(temp) == visited.end()) {

                            // Pehli baar discover hua
                            visited.insert(temp);

                            // Baad mein process karenge
                            q.push(temp);
                        }
                    }
                }
            }

            // Current level complete
            count++;
        }


        // Transformation possible nahi hai
        return 0;
    }
};