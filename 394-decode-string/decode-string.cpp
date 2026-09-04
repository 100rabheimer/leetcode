class Solution {
public:
    string decodeString(string s) {
        stack<int>countStack;

stack<string> stringStack;
        int currentNumber=0;
        string currentString="";
 for(char ch : s) {

   // Case 1: digit
            if(isdigit(ch)) {
                currentNumber = currentNumber * 10 + (ch - '0');
            }
            else if(isalpha(ch)){
                    currentString += ch;
            }
               // Case 2: opening bracket
            else if(ch == '[') {
                countStack.push(currentNumber);//currentnumber ko stack mein
                stringStack.push(currentString);

                currentNumber = 0;
                currentString = "";
            }
            else if(ch == ']'){
                int count = countStack.top();
                countStack.pop();

                string previous = stringStack.top();
                stringStack.pop();


                //ab current string ko count time reopeat krna hai
                string temp = "";

for(int i = 0; i < count; i++) {
    temp += currentString;
}//then current ko previous ke sath merge
     currentString = previous + temp;
            }
 }
 return currentString;
    }
};