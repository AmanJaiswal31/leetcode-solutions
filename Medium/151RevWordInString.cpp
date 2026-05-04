// Problem: Reverse Words in a String
// Link: https://leetcode.com/problems/reverse-words-in-a-string/
// Difficulty: Medium
// Approach: Two Pointers + Reverse Words
// Time: O(n) | Space: O(1) (ignoring output string)

class Solution {
public:
    string reverseWords(string s) {

        string str;
        string word;

        int i=s.length()-1;

        while(i>=0){
            word="";
            while(i>=0 && s[i]!=' '){
                word+=s[i];
                i--;
            }

            reverse(word.begin(), word.end());
            if(!word.empty()){
                if(!str.empty()) str+=' ';
                str+=word;
            }
            
           i--;
        }

        return str;
  
    }
};
 03














 